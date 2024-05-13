/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fichiari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:59:06 by fichiari          #+#    #+#             */
/*   Updated: 2024/05/06 09:53:39 by fichiari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *string, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!string || !f)
		return ;
	i = 0;
	while (string[i])
	{
		f(i, &string[i]);
		i++;
	}
}
