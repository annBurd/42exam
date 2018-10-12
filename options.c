/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:40:35 by exam              #+#    #+#             */
/*   Updated: 2018/10/12 17:52:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

# define ERROR "options: abcdefghijklmnopqrstuvwxyz\n"
# define ERROR2 "Invalid Optioni\n"

#include <stdio.h>
size_t	str_len(char *s)
{
	size_t	i;
	
	i = 0;
	while (*s++)
		i++;
	return (i);
}

int		valid_options(char **argv)
{
	int	i;
	int	t;

	i = 1;
	while (argv[i])
	{
		t = 0;
		while (argv[i][t])
		{
			if (argv[i][t] == 'h')
			{
				write(1, ERROR, str_len(ERROR));
				return (0);
			}
			else if ((argv[i][t] < 'a' || argv[i][t] > 'z') && argv[i][t] != '-')
			{
				write(1, ERROR2, str_len(ERROR2));
				return (0);
			}
			t++;
		}
		i++;
	}
	return (1);
}

int		zero(char c)
{
	int i;

	i = c - 96;
	printf("c = '%c', i =  %d\n", c, i);
	if (i > 8 && i <= 16)
		i++;
	else if (i > 16 && i <= 24)
		i += 2;
	else if (i > 24)
		i += 3;
	printf("i =  %d\n", i);
	return (i);
}

size_t	start(int i, char **ar, char *out)
{
	size_t	size;
	int		a;

	size = str_len(out);
	while (ar[i])
	{
		a = 0;
		if (ar[i][a] == '-')
		{
			a++;
			while (ar[i][a])
			{
				printf("%lu\n", size - 1 - zero(ar[i][a]));
				out[size - 1 - zero(ar[i][a])] = '1';
				printf("out - %s", out);
				a++;
			}
		}
		i++;
	}
	return (size);
}

int		main(int argc, char ** argv)
{
	char	*out;
	size_t	size;

	if (argc == 1)
		write(1, ERROR, str_len(ERROR));
	else if (valid_options(argv))
	{
		out = "00000000 00000000 00000000 00000000\n";
		size = start(1, argv, out);
		write(1, out, size);
	}


	return (0);
}
