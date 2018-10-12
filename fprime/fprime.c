/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:17:25 by exam              #+#    #+#             */
/*   Updated: 2018/10/12 14:41:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	get_prime(size_t i, size_t prime)
{
	while (prime < i)
	{
		if (i % prime == 0)
			return (prime);
		else
			prime++;
	}
	return (prime);
}

void	fprime(size_t i)
{
	size_t prime;

	if (i <= 1)
		prime = 1;
	else
		prime = get_prime(i, 2);
	printf("%zu", prime);
	i /= prime;
	while (i > 1)
	{
		prime = get_prime(i, prime);
		printf("*%zu", prime);
		i /= prime;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
	return (0);
}
