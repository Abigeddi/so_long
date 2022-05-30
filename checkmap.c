/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abigeddi <abigeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:47:30 by abigeddi          #+#    #+#             */
/*   Updated: 2022/05/30 10:33:55 by abigeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**store_map(char *map)
{
	int		fd;
	char	*line;
	char	*all_lines;
	char	**res;

	line = "";
	all_lines = ft_strdup("");
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error: invalid file descriptor\n", 31), exit(1), NULL);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free (line);
	}
	free (line);
	close (fd);
	if (all_lines[0] == '\0')
		return (write(2, "Error:no map readed\n", 22), exit(1), NULL);
	res = ft_split(all_lines, '\n');
	return (res);
}

int	check_file_type(char *s, char *type)
{
	int	i;

	i = 0;
	while (type[i])
	{
		if (type[i] != s[i])
			return (0);
		i++;
	}
	if (s[i] == '\0')
		return (1);
	return (0);
}

void	check_file(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (check_file_type(s + i, ".ber"))
				return ;
		}
		i++;
	}
	write(2, "ERROR: invalid file type\n", 26);
	exit(1);
}
