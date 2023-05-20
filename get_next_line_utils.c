/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:50:51 by brpereir          #+#    #+#             */
/*   Updated: 2023/05/20 18:41:00 by brpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int ft_strchr(const *str)
{
	size_t	i;

	i = -1;
	while(str[++i])
	{
		if(str[i] == '\n')
			return 1;	
	}
	return 0;
}

unsigned int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char *join_string(char *first, char *copy)
{
	size_t	i;
	size_t	j;
	char *temp;

	temp = (char *)malloc(sizeof(char) * (ft_strlen(first) + ft_strlen(copy) + 1));
	if(!temp)
		return (NULL);
	i = 0;
	while(i < ft_strlen(first))
	{
		temp[i] = first[i];
		i++;
	}
	j = i;
	i = 0;
	while(i < ft_strlen(copy))
		temp[j++] = copy[i++];	
	temp[i] = 0;
	free(first);
	return (temp);
}

