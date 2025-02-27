/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:50:14 by yaboumei          #+#    #+#             */
/*   Updated: 2025/02/27 13:50:18 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == INT_MIN)
	{
		ft_putstr_fd("-2147483648", 1);
		return ;
	}
	if (n < 0)
	{
		ft_putstr_fd("-", 1);
		n = -n;
	}
	if (n / 10)
		ft_putnbr(n / 10);
	ft_putchar(((n % 10) + '0'));
}
