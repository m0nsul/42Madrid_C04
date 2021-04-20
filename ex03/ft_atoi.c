/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolano- <jsolano-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:11:06 by jsolano-          #+#    #+#             */
/*   Updated: 2021/04/20 11:36:37 by jsolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	unsigned int	i;
	int				result;

	result = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = 1;
		}
		else
		{
			result = 0;
			return (result);
		}
		i++;
	}
	return (result);
}

int	ft_isspace (unsigned char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_isnumeric (char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_evaluate_sign (char c)
{
	if (c != '-' && c != '+')
	{
		return (0);
	}
	if (c == '-')
	{
		return (-1);
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	exp;
	int	result;

	exp = 1;
	result = 0;
	sign = 1;
	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			;
		else if (!(ft_isnumeric(str[i]) || ft_evaluate_sign(str[i])))
			break ;
		else if (str[i] == '+' || str[i] == '-')
			sign *= ft_evaluate_sign (str[i]);
		else if (ft_isnumeric(str[i]))
		{
			result *= 10;
			result += (str[i] - 48);
		}
		i++;
	}
	return (sign * result);
}
