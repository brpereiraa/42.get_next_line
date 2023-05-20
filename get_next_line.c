/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:51:05 by brpereir          #+#    #+#             */
/*   Updated: 2023/05/20 18:41:28 by brpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *clean_line(char *str)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	j = 0;
	while(str[i] && str[i] != '\n')
		i++;
	temp = (char *)malloc(sizeof(char) * i);
	while(j < i)
	{
		temp[j] = str[j];
		j++;
	}
	return (temp);
}

static char *get_text(char *str, int fd)
{
	char *temp;
	int nbytes;

	temp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	nbytes = 1;
	while (nbytes > 0 && ft_strchr())
	{
		nbytes = read(fd, temp, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free (temp);
			free (str);
			return (NULL);
		}
		str = join_string(str, temp);
		// printf("helo");
		// printf("%s", str);
	}
	free(temp);
	return (str);
}

char *get_next_line(int fd)
{
	static char *str; 
	char *line;

	get_text(str, fd);
	line = clean_line(str);
	return (str);
}

int main(void)
{
	int fd;

	fd = open("a.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	return (0);
}