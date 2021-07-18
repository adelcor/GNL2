/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-cor <adel-cor@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 10:02:50 by adel-cor          #+#    #+#             */
/*   Updated: 2021/07/12 10:43:14 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	search_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	eraser(int ret, char *buf)
{
	if (ret == -1)
	{
		free(buf);
		return (0);
	}
	return (1);
}

char	*catch_line(char *str)
{
	int		i;
	int	x;
	char	*temp;

	i = 0;
	x = 0;
	if (!str || ft_strlen(str) == 0)
		return(NULL);
	while (str[i])
	{	
		if (str[i++] == '\n')
			break;
	}
	temp = (char *)ft_calloc(1, i + 1);
	if (!temp)
		return (0);
	while (x < i)
	{
		temp[x] = str[x];
		x++;
	}
	temp[x] = '\0';
	return (temp);
}

char	*catch_box(char *box)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!box)
		return (0);
	while (box[i] && box[i] != '\n')
		i++;
	if (!box[i])
	{
		free(box);
		return (0);
	}
	temp = (char *)ft_calloc(1, ((ft_strlen(box) - i) + 1));
	if (!temp)
		return (0);
	i++;
	while (box[i])
		temp[j++] = box[i++];
	temp[j] = '\0';
	free(box);
	return (temp);
}

char	*get_next_line(int fd)
{	
	char		*line;
	char		*buf;
	static char	*box[4096];
	int			ret;

	ret = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)ft_calloc(1, BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!search_nl(box[fd]) && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (!eraser(ret, buf))
			return (NULL);
		buf[ret] = '\0';
		box[fd] = join_str(box[fd], buf);
	}
	free(buf);
	line = catch_line(box[fd]);
	box[fd] = catch_box(box[fd]);
	return (line);
}
