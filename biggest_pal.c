/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:43:49 by exam              #+#    #+#             */
/*   Updated: 2018/10/12 16:25:54 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// = Test 3 ===================================================
// $> ./ct41i2mjy6ptxngqrpqq7wyf abbabbbabba
// $> diff -U 3 user_output_test3 test3.output | cat -e
// Binary files user_output_test3 and test3.output differ$
// Diff KO :(

#include <unistd.h>

size_t	check(char *s, size_t i, short zz, size_t *n)
{
	int t;

	t = i - (!zz ? 1 : 2);
	while (t >= 0 && s[i])
	{
		if (s[i] != s[t])
			break ;
		i++;
		t--;
	}
	*n = t + 1;
	return (i - t - 1);
}

size_t	biggest_pal(char *s, size_t *size)
{
	size_t	i;
	size_t	n;
	size_t	tmp;

	tmp = 0;
	i = 1;
	n = 0;
	while (s[i])
	{
		if (s[i] == s[i - 1])
		{
			tmp = check(s, i, 0, &n);
			tmp >= *size && (*size = tmp);
		}
		if (s[i] == s[i - 2])
		{
			tmp = check(s, i, 1, &n);
			tmp >= *size && (*size = tmp);
		}
		i++;
	}
	i == 1 && (*size = 1);
	return (n);
}

int		main(int argc, char **argv)
{
	size_t	size;
	size_t	i;
	char	*s;

	if (argc == 2)
	{
		s = argv[1];
		size = 0;
		i = biggest_pal(s, &size);
		write(1, s + i, size);
	}
	write(1, "\n", 1);
	return (0);
}
