/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:29:43 by mreidenb          #+#    #+#             */
/*   Updated: 2023/01/03 14:57:29 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (n-- > 0)
		*ptr++ = c;
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (size > 0 && (__LONG_LONG_MAX__ / size) < count)
		return (0);
	mem = (char *) malloc(count * size);
	if (!mem)
		return (mem);
	ft_memset (mem, 0, count * size);
	return (mem);
}

size_t	ft_isnewline(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		j;
	int		comblen;

	i = 0;
	j = 0;
	comblen = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *) ft_calloc(comblen + 1, 1);
	if (!newstr)
		return (0);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	free((char *)s1);
	return (newstr);
}
