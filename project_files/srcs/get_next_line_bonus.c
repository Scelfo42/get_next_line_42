/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:20:54 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/19 16:33:40 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*join_buf_to_heap(char *dst, char *src, ssize_t byte, size_t q_mem)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!src || byte == 0)
		return (dst);
	else if (dst != NULL)
	{
		while (dst[i] != '\0')
			i++;
	}
	tmp = ft_strdup(dst);
	dst = ft_calloc(sizeof(char), (q_mem + byte + 1));
	dst = ft_cpy(dst, tmp, src, i);
	ft_free(&tmp);
	return (dst);
}

static char	*form_static(char *str)
{
	size_t	c;
	size_t	c_cl;
	char	*clean_line;

	c = 0;
	while (str[c] != '\n')
	{
		if (str[c] == '\0')
			return (NULL);
		c++;
	}
	c_cl = c;
	while (str[c_cl] != '\0')
		c_cl++;
	clean_line = ft_calloc(sizeof(char), (c_cl - c));
	c_cl = 0;
	while (str[c] != '\0')
		clean_line[c_cl++] = str[++c];
	return (clean_line);
}

static char	*cut_to_line(char *str_to_cut, char *buf)
{
	int		i;
	int		size;
	char	*cutted;

	if (!buf || !*buf)
		return (str_to_cut);
	i = 0;
	size = 0;
	while (str_to_cut[size] != '\n')
		size++;
	size += 1;
	cutted = ft_calloc(sizeof(char), (size + 1));
	while (i < size)
	{
		cutted[i] = str_to_cut[i];
		i++;
	}
	ft_free(&str_to_cut);
	return (cutted);
}

static char	*read_add_to_heap(int fd, char *statica, ssize_t reader)
{
	char	*s;
	int		new_line;
	size_t	count;

	new_line = 0;
	count = 1;
	while (new_line == 0 && reader > 0)
	{
		s = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		reader = read(fd, s, BUFFER_SIZE);
		if (statica)
		{
			while (statica[count] != '\0')
				count++;
		}
		statica = join_buf_to_heap(statica, s, reader, count);
		ft_free(&s);
		if (!statica)
			break ;
		new_line = found_new_line(statica);
		if (reader == 0 && new_line == 0)
			break ;
	}
	return (statica);
}

char	*get_next_line(int fd)
{
	static char	*buf[1024];
	char		*line;
	ssize_t		reader;

	reader = BUFFER_SIZE;
	if (fd < 0 || reader <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = read_add_to_heap(fd, buf[fd], reader);
	if (!line || !*line)
	{
		ft_free(&buf[fd]);
		return (NULL);
	}
	buf[fd] = form_static(line);
	if (line)
	{
		if (!buf[fd] || !*buf[fd])
			ft_free(&buf[fd]);
		line = cut_to_line(line, buf[fd]);
		return (line);
	}
	ft_free(&line);
	return (NULL);
}

int	main(void)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*line;
	char	*line2;
	char	*line3;
	int		check = 0;
	int		check2 = 0;
	int		check3 = 0;

	fd = open("test", O_RDONLY);
	fd2 = open("test2", O_RDONLY);
	fd3 = open("test3", O_RDONLY);
	while (!check || !check2 || !check3)
	{
		line = get_next_line(fd);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);
		if (!line)
			check = 1;
		if (!line2)
			check2 = 1;
		if (!line3)
			check3 = 1;
		printf("file 1: %s", line);
		printf("file 2: %s", line2);
		printf("file 3: %s\n", line3);
		ft_free(&line);
		ft_free(&line2);
		ft_free(&line3);
	}
	return (0);
}
