/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 04:52:38 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/07 06:15:40 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define	GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_strdup(const char *s);

#endif