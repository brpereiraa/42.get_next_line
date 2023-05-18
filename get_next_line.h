/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:31:17 by marvin            #+#    #+#             */
/*   Updated: 2023/04/28 11:31:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE 42
# endif

#include <stdio.h>

void	get_next_line_utils(char *str, int i, int fd, int n);
char	*get_next_line(int fd);