/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-23 12:22:32 by dbislimi          #+#    #+#             */
/*   Updated: 2024-04-23 12:22:32 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *save)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	while (j <= i)
	{
		line[j] = save[j];
		j++;
	}
	if (save[j - 1] == '\n')
		line[j] = '\0';
	return (line);
}

char	*remove_previous_line(char	*save)
{
	char	*new_save;
	size_t	savelen;
	size_t	i;
	size_t	j;

	i = 0;
	new_save = NULL;
	savelen = ft_strlen(save);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
	{
		j = 0;
		new_save = malloc(sizeof(char) * (savelen - i + 1));
		if (!new_save)
			return (NULL);
		i++;
		while (save[i])
			new_save[j++] = save[i++];
		new_save[j] = '\0';
	}
	free(save);
	return (new_save);
}

char	*ft_update(char *save, char *buf)
{
	char	*temp;

	temp = ft_strjoin(save, buf);
	free(save);
	return (temp);
}

char	*ft_read(char *save, int fd)
{
	int		bytes;
	char	*buf;

	if (!save)
		save = ft_strdup("");
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf || !save)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(save);
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		save = ft_update(save, buf);
		if (ft_strchr(save, '\n'))
			break ;
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = ft_read(save[fd], fd);
	if (save[fd] == NULL)
		return (NULL);
	line = get_line(save[fd]);
	save[fd] = remove_previous_line(save[fd]);
	if (line[0] == '\0')
	{
		free(save[fd]);
		free(line);
		return (NULL);
	}
	return (line);
}
/*
int main(void)
{
	char *line;
	int fd;
	int fd2;
	int i;
	int j;

	i = 0;
	j = 0;
	fd = open("text.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	printf("\033[0;31m\nfd :\n\033[0m");
	while (i < 2)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			printf("(null)\n");
			break;
		}
		else
			printf("\e[36mligne %d : \e[0m%s\e[36m\e[0m\n", i+1, line);
		i++;
	}
	printf("\033[0;31m\nfd2 :\n\033[0m");
	while (j < 2)
	{
		line = get_next_line(fd2);
		if (line == NULL)
		{
			printf("(null)\n");
			break;
		}
		else
			printf("\e[36mligne %d : \e[0m%s\e[36m\e[0m\n", j+1, line);
		j++;
	}
	printf("\033[0;31m\nfd :\n\033[0m");
	while (i < 4)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			printf("(null)\n");
			break;
		}
		else
			printf("\e[36mligne %d : \e[0m%s\e[36m\e[0m\n", i+1, line);
		i++;
	}
	printf("\033[0;31m\nfd2 :\n\033[0m");
	while (j < 5)
	{
		line = get_next_line(fd2);
		if (line == NULL)
		{
			printf("(null)\n");
			break;
		}
		else
			printf("\e[36mligne %d : \e[0m%s\e[36m\e[0m\n", j+1, line);
		j++;
	}
}*/