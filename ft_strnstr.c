/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fichiari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:59:06 by fichiari          #+#    #+#             */
/*   Updated: 2024/05/06 15:06:04 by fichiari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	if (*needle == 0)
		return ((char *)haystack);
	if (*haystack == 0)
		return (NULL);
	needle_len = ft_strlen(needle);
	if (needle_len > len)
		return (NULL);
	i = 0;
	while (i <= len - needle_len)
	{
		if (ft_strncmp(haystack + i, needle, needle_len) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
