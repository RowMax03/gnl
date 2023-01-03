/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:29:38 by mreidenb          #+#    #+#             */
/*   Updated: 2023/01/03 17:00:46 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*buffer_getter(int fd, char *buf)
{
	char	*tmp;
	int		i;

	i = 1;
	if (!buf)
		buf = ft_calloc(sizeof(char), 1);
	if (!buf)
		return (NULL);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	while (i != 0 && !ft_isnewline(buf))
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i == -1)
			return (free(tmp), free(buf), NULL);
		tmp[i] = '\0';
		buf = ft_strjoin(buf, tmp);
	}
	free (tmp);
	return (buf);
}

char	*line_setter(char *buf)
{
	int		i;
	char	*line;

	if (buf[0] == 0)
		return (NULL);
	i = 1;
	while (buf[i] && buf[i - 1] != '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*new_buffer(char *buf)
{
	char	*new_buffer;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == 0)
		return (free (buf), NULL);
	new_buffer = ft_calloc((ft_strlen(buf) - i + 1), sizeof(char));
	if (!new_buffer)
		return (NULL);
	i++;
	while (buf[i])
		new_buffer[j++] = buf[i++];
	new_buffer[j] = 0;
	free (buf);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf[1024];

	if (BUFFER_SIZE <= 0 || (fd < 0 || fd > 1024))
		return (NULL);
	buf[fd] = buffer_getter(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = line_setter(buf[fd]);
	buf[fd] = new_buffer(buf[fd]);
	return (line);
}
