/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 07:56:00 by rnitta            #+#    #+#             */
/*   Updated: 2020/02/23 13:50:43 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check(int b, char *base)
{
	int i;
	int ii;

	if (b <= 1)
		return (0);
	i = 0;
	while (i < b)
	{
		if ((*(base + i) <= 13 && *(base + i) >= 9) || *(base + i) == 32)
			return (0);
		if (*(base + i) == 43 || *(base + i) == 45 || b < 2)
			return (0);
		ii = i + 1;
		while (ii < b)
		{
			if (*(base + i) == *(base + ii))
				return (0);
			ii++;
		}
		i++;
	}
	return (1);
}

int		f(char *str, char *base, int b, int d)
{
	int i[6];

	i[2] = 0;
	i[0] = 0;
	i[4] = 0;
	i[5] = 0;
	i[3] = 0;
	while (*(str + d + i[0]) != '\0' && i[3] < b)
	{
		i[3] = 0;
		while (i[3] < b)
		{
			if (*(str + d + i[0]) == *(base + i[3]))
			{
				i[4] = b * i[4] + i[3];
				i[2]++;
				i[5] = 1;
				break ;
			}
			i[3]++;
		}
		i[0]++;
	}
	return (i[4]);
}

int		ft_atoi_base(char *str, char *base)
{
	int				b;
	int				i;
	int				p;

	b = 0;
	while (*(base + b) != '\0')
	{
		b++;
	}
	i = 0;
	while ((*(str + i) <= 13 && *(str + i) >= 9) || *(str + i) == 32)
	{
		i++;
	}
	p = 1;
	while (*(str + i) == '+' || *(str + i) == '-')
	{
		if (*(str + i) == '-')
			p = (-1) * p;
		i++;
	}
	return (check(b, base) * p * f(str, base, b, i));
}
