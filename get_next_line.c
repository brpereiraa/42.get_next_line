/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:33:06 by marvin            #+#    #+#             */
/*   Updated: 2023/04/26 14:33:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_line(int fd, char *str)
{
	char	*temp;
	int		n_read;
	
	n_read = 1;
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (n_read > 0)
	{
		n_read = read(fd, temp, BUFFER_SIZE);
		if(n_read == -1)
		{
			free(temp);
			return (NULL);	
		}
		temp[n_read] = 0;
		break;
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*temp;
	int				i;
	int 			flag;
	int				bytes_read;

	i = 0;
	while(1)
	{
		if(read(fd, temp, BUFFER_SIZE) == -1)
			return NULL;
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE*2));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		strjoin(buffer, temp, buffer);
		free(temp);
	}
	temp = buffer;
	free(buffer);
	return(temp);
}


int main()
{
	int fd = open("a.txt", O_RDONLY);
	char *a;

	while ((a = get_next_line(fd)))
	{
		printf("%s", a);
	}

	printf("%s", get_next_line(fd));

	return 0;
} 