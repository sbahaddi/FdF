/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 06:22:03 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/01/22 06:48:43 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		f_power(int nbr, int puis)
{
	int res;

	res = 1;
	while (puis-- > 0)
		res *= nbr;
	return (res);
}

char	*ft_strrev(char *t)
{
	int		i;
	int		j;
	char	aide;

	i = 0;
	j = strlen(t) - 1;
	while (i < j)
	{
		aide = t[i];
		t[i++] = t[j];
		t[j--] = aide;
	}
	return (t);
}

int		convert_to_dec(char *str)
{
	int	i;
	int	si;
	int	nbr;

	i = 0;
	si = 1;
	nbr = 0;
	str = ft_strrev(str);
	while (str[i])
	{
		if (str[i] == '-')
			si = -1;
		if (str[i] >= '0' && str[i] <= '9')
			nbr += (str[i] - '0') * f_power(16, i);
		if (str[i] >= 'a' && str[i] <= 'z')
			nbr += (str[i] - 'a' + 10) * f_power(16, i);
		if (str[i] >= 'A' && str[i] <= 'Z')
			nbr += (str[i] - 'A' + 10) * f_power(16, i);
		i++;
	}
	return (nbr * si);
}
