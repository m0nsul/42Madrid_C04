/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolano- <jsolano-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:11:06 by jsolano-          #+#    #+#             */
/*   Updated: 2021/04/20 13:55:16 by jsolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (*(str + count++))
		;
	return (--count);
}

int	ft_base_char_repeated (char *base)
{
	int	i;
	int	j;

	i = -1;
	while (base[++i])
	{
		j = -1;
		while (base[++j])
			if (base[i] == base[j] && i != j)
				return (1);
	}
	return (0);
}

int	ft_check_errors_putnbr_base (char *base)
{
	int	size_base;
	int	i;
	int	has_sign;

	has_sign = 0;
	i = -1;
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-')
			has_sign = 1;
	}
	size_base = ft_strlen(base);
	if (size_base <= 1 || ft_base_char_repeated(base))
		return (0);
	else if (has_sign)
		return (0);
	return (1);
}

void	ft_ft_putnbr_base(int nbr, char *base, unsigned int size_base)
{
	int				div;
	int				mod;
	unsigned int	nbr_unsigned;

	if (nbr < 0)
	{
		nbr_unsigned = (unsigned int)(-1 * nbr);
		write(1, "-", 1);
	}
	else
		nbr_unsigned = (unsigned int)nbr;
	if (nbr_unsigned >= size_base)
	{
		div = nbr_unsigned / size_base;
		mod = nbr_unsigned % size_base;
		ft_ft_putnbr_base(div, base, size_base);
		write(1, &base[mod], 1);
	}
	else
		write(1, &base[nbr_unsigned], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	size_base;

	if (!(ft_check_errors_putnbr_base (base)))
		return ;
	size_base = ft_strlen(base);
	ft_ft_putnbr_base(nbr, base, size_base);
}
