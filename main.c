/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:06:39 by hmoulher          #+#    #+#             */
/*   Updated: 2018/12/05 15:13:09 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char const *argv[])
{
	int		i;
	int		verif;
	int		*fd_buff;
	char	*str;

	i = 0;
	if (argc > 1)
	{
		fd_buff = (int*)malloc(sizeof(int) * (argc - 1));
		while (i < argc)
		{
			fd_buff[i] = open(argv[i + 1], O_RDONLY);
			i++;
		}
		i = 0;
		while (i < argc - 1)
		{
			while((verif = get_next_line(fd_buff[i], &str)))
			{
				printf("%s\n", str);
				if(verif <= 0)
				{
					printf("error\n");
					return (0);
				}
				free(str);
			}
			i++;
		}
		i = 0;
		while (i < argc)
		{
			close(fd_buff[i]);
			i++;
		}
		free(fd_buff);
	}
	return (0);
}
