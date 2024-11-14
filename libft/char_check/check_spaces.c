#include "libft.h"

bool	check_spaces(int c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (true);
	return (false);
}
