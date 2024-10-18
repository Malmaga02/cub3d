#include "../cubed.h"

//che tutti i caratteri siano 0 1 o N/S/W/E oppure spazi 
//(che riempio con 0 se sono all'interno o con 1 se sono all'esterno)
// che sia chiusa (tutti le linee devono avere 1 all'inizio e 1 alla fine)
//che la prima e l'ultima linea siano solo composte da 1

//ho creato la mia matrice - fare controlli del caso
// prima e ultima riga solo 1 e i primi e ultimi char di ogni stringa solo 1 ||
// presenza char diversi da 0 1 o N/S/W/E (non si possono ripetere) ||
// chiusura della mappa, precisa (capire ancora come fare)
// gestire gli spazi all'interno della mappa (gestirli come 0? )
// necessita di algoritmo che mi controlla gli spazi, ovvero se ho degli spazi 
//a indice x di una matrice, devo controllare che la mappa sia comunque chiusa

char	*get_map_strings(int fd, int flag)
{
	char	*read_line;
	char	*content;

	read_line = get_next_line(fd);
	if (flag == 0)
	{
		while (read_line && !is_external_row(read_line))
		{
			free(read_line);
			read_line = get_next_line(fd);
			if (!read_line)
				return (error(MISSING_MAP), free(read_line), NULL);
		}
	}
	if (!read_line || (read_line && !*read_line))
		return (free(read_line), NULL);
	content = ft_strdup(read_line);
	free(read_line);
	return (content);
}

char	**parse_map(char *name_file)
{
	t_list	*head;
	t_list	*node;
	int		fd;
	char	*content;

	fd = open(name_file, O_RDONLY);
	if (fd == -1)
		return (close(fd), NULL);
	head = NULL;
	content = get_map_strings(fd, 0);
	while (content)
	{
		node = ft_lstnew((void *)ft_strdup(content));
		if (!node)
			return (ft_lstclear(&head, free), close(fd), free(content), NULL);
		ft_lstadd_back(&head, node);
		free(content);
		content = get_map_strings(fd, 1);
	}
	close(fd);
	if (!head)
		return (error(ERROR_MAP), NULL);
	return (lst_to_mtx(head));
}
