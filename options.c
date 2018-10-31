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

#include <stdio.h>

void	write_str(char *s)
{
	size_t	i;
	
	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	write(1, "\n", 1);
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
				write_str("options: abcdefghijklmnopqrstuvwxyz");
				return (0);
			}
			else if ((argv[i][t] < 'a' || argv[i][t] > 'z') && argv[i][t] != '-')
			{
				write_str("Invalid Option");
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

void	start(int i, char **ar, char *out)
{
	const size_t	size = 35;
	int				a;

	while (ar[i])
	{
		a = 0;
		if (ar[i][a] == '-')
		{
			a++;
			while (ar[i][a])
			{
				printf("%lu\n", size - zero(ar[i][a]));
				out[size - zero(ar[i][a])] = '1';
				printf("out - %s", out);
				a++;
			}
		}
		i++;
	}
}

int		main(int argc, char ** argv)
{
	const size_t	size = 35;
	char			*out;

	if (argc == 1)
		write_str("options: abcdefghijklmnopqrstuvwxyz");
	else if (valid_options(argv))
	{
		out = "00000000 00000000 00000000 00000000";
		start(1, argv, out);
		write(1, out, size);
	}


	return (0);
}
