/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 10:02:03 by exam              #+#    #+#             */
/*   Updated: 2018/10/05 12:23:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	len(char *s, size_t value)
{
	size_t	size;

	size = 0;
	if (!s)
	{
		if (!value)
			return (1);
		while (value)
		{
			value /= 10;
			size++;
		}
	}
	else
		while (*s++)
			size++;
	return (size);
}

char	*get_param(size_t pr, size_t value)
{
	if (!pr)
		return (value == 1 ? "second" : "seconds");
	else if (pr == 1)
		return (value == 1 ? "minute" : "minutes");
	else if (pr == 2)
		return (value == 1 ? "hour" : "hours");
	else if (pr == 3)
		return (value == 1 ? "month" : "months");
	return (0);
}

size_t	get_value(unsigned int sec, size_t value, size_t *pr)
{
	value = sec;
	if (!(*pr) && value / 60)
	{
		value /= 60;
		(*pr)++;
	}
	if (*pr == 1 && value / 60)
	{
		value /= 60;
		(*pr)++;
	}
	if (*pr == 2 && value / 60)
	{
		value /= 24;
		(*pr)++;
	}
	if (*pr == 3 && value / 30)
	{
		value /= 30;
		(*pr)++;
	}
	return (value);
}

void	cpy(char *s, size_t *i, char *s2, size_t num)
{
	size_t	t;

	t = !s2 ? len(0, num) - 1 : 0;
	if (!s2 && !num)
		s[*i++] = '0';
	else if (!s2 && num)
		while (num)
		{
			s[*i + t--] = num % 10 + '0';
			num /= 10;
		}
	else
		while (s2[t])
			s[(*i)++] = s2[t++];
}

char	*moment(unsigned int duration)
{
	char	*param;
	char	*out;
	size_t	size;
	size_t	value;

	size = 0;
	value = get_value(duration, 0, &size);
	param = get_param(size, value);
	size = len(0, duration) + len(0, value) + len(param, 0) + 6;
	out = (char*)malloc(sizeof(char) * size);
	out[size] = 0;
	size = 0;
	cpy(out, &size, 0, value);
	size += len(0, value);
	cpy(out, &size, " ", 0);
	cpy(out, &size, param, 0);
	cpy(out, &size, " ago.", 0);
	free(out);
	return (out);
}

int		main()
{
	char *s = moment(2500);
	printf("%s\n", s);
	return (0);
}
