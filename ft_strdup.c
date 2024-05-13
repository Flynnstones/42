/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fichiari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:59:06 by fichiari          #+#    #+#             */
/*   Updated: 2024/05/02 12:29:40 by fichiari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	void	*dup;

	len = ft_strlen(s1) + 1;
	dup = (void *)malloc(len);
	if (dup != NULL)
	{
		ft_memcpy(dup, s1, len);
	}
	return (dup);
}
