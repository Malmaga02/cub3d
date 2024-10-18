/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:14:08 by mgalmari          #+#    #+#             */
/*   Updated: 2024/04/30 18:09:06 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include <string.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdint.h>
# include <sys/stat.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_dll
{
	int				value;
	int				index;
	struct s_dll	*prev;
	struct s_dll	*next;
}					t_dll;

// allocating_strings
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_get_substr(char *read_line, int index, int len);
char	*ft_freejoin(char *read_line, char *buffer);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

// char_check
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

// conversions
int		ft_atoi(const char	*nptr);
long	ft_atol(const char *str);
char	*ft_itoa(int n);

// ft_printf
void	ft_printf_putstr(char *s, int *fin);
void	ft_printf_format(char c, va_list arg, int *fin);
void	ft_printf_putmemory(unsigned long long ptr, int *fin, int ox);
void	ft_printf_putnbr_b(unsigned int nbr, int *fin);
void	ft_printf_putnbr(int n, int *fin);
void	ft_printf_putchar(int c, int *fin);
void	ft_printf_puthex(char c, unsigned int nbr, int *fin);
int		ft_printf(const char *s, ...);

// working_with_files
char	*get_next_line(int fd);

// list_handling
	// linked_list
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
	//d_linked_list
void	dll_add_back(t_dll **lst, t_dll *new);
void	dll_add_front(t_dll **lst, t_dll *new);
t_dll	*dll_iterate(t_dll *lst);
t_dll	*dll_last(t_dll *lst);
void	dll_clear(t_dll **lst);
t_dll	*dll_new(int value);
int		dll_size(t_dll *lst);
int		find_min_index(t_dll *pStack);
int		find_min_value(t_dll *pStack);
int		find_max_index(t_dll *pStack);
int		find_max_value(t_dll *pStack);
void	set_index(t_dll **list);

// memory_handling
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

// mtx_handling
int		count_rows(char **mtx);
void	free_mtx(char **mtx_map, int x);
char	**ft_mtxdup(char **mtx);

// printing_functions
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

// string_handling
void	ft_bzero(void *s, size_t n);
int		ft_get_newline(char *read_line);
int		ft_lencmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_strlen(const char *s);
int		ft_strlen_chr(char *str, int c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
