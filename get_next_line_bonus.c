/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:51:05 by brpereir          #+#    #+#             */
/*   Updated: 2023/06/08 16:54:44 by brpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*clean_line(char *str)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	temp = (char *)malloc(sizeof(char) * i);
	while (j < i)
	{
		temp[j] = str[j];
		j++;
	}
	return (temp);
}

static char	*str_rest(char *str)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	j = 0;
	while (str[i++])
		j++;
	temp = (char *)malloc(sizeof(char) * (j + 1));
	i -= j;
	j = 0;
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = 0;
	free (str);
	return (temp);
}

static char	*get_text(char *str, int fd)
{
	char	*temp;
	int		nbytes;

	temp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	nbytes = 1;
	while (nbytes > 0 && ft_strchr(temp))
	{
		nbytes = read(fd, temp, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free (temp);
			free (str);
			return (NULL);
		}
		str = join_string(str, temp);
	}
	free (temp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	str[fd] = get_text(str[fd], fd);
	if (!str[fd])
		return (NULL);
	line = clean_line(str[fd]);
	str[fd] = str_rest(str[fd]);
	return (line);
}

// int main(void)
// {
// 	int fd;

// 	fd = open("a.txt", O_RDONLY);
// 	printf("%s\n", get_next_line(fd));
// 	return (0);
// }