/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 10:03:59 by exam              #+#    #+#             */
/*   Updated: 2018/09/28 11:28:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

void	ps(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

size_t	count_word(char *s)
{
	size_t i;

	i = 0;
	while (*s)
	{
		if (*s == ' ' || *s == '\t' || *(s + 1) == 0)
			i++;
		s++;
	}
	return (i);
}

char	*cpy_line(char *res, char *s, size_t n)
{
	size_t	i;

	if (!n || !*s)
		return (res);
	i = 0;
	while (*s && i < n)
	{
		res[i++] = *s;
		s++;
	}
	return (res);
}

char	**fill_de_arr(char **arr, char *s, size_t size)
{
	char	*point;
	size_t	i;

	i = 0;
	point = s;
	while (*s)
	{
		if (*(s - 1) == ' ' || *(s - 1) == '\t')
			point = s;
		if (*(s + 1) == ' ' || *(s + 1) == '\t' || *(s + 1) == 0)
		{
			size = s - point + 1;
			arr[i] = (char*)malloc(sizeof(char) * (size + 1));
			arr[i][size] = 0;
			arr[i] = cpy_line(*(arr + i), point, size);
			i++;
		}
		s++;
	}
	return (arr);
}

int		main(int argc, char **argv)
{
	char	**arr;
	size_t	size;

	if (argc == 2 && argv[1][0])
	{
		size = count_word(argv[1]);
		arr = (char**)malloc(sizeof(char*) * (size + 1));
		arr[size] = 0;
		arr = fill_de_arr(arr, argv[1], size);
		while (arr[--size])
		{
			ps(arr[size]);
			if (size > 0)
				write(1, " ", 1);
			free(arr[size]);
			if (!size)
				break ;
		}
		free(arr);
	}
	write(1, "\n", 1);
	return (0);
}
