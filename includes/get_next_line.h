/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:06:03 by mah-ming          #+#    #+#             */
/*   Updated: 2025/04/29 16:11:50 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		read_file(char **valueholder, int bytes, int fd);
char	*insert_line(char **valueholder, int len);
void	update_holder(char **valueholder);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *s1, char c);
int		readfile_helper(int bytes, char **temp);
char	*gnl_helper(char **value, int result);
char	*ft_strdup(const char *src);

#endif