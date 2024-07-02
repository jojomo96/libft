/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:30:31 by lzipp             #+#    #+#             */
/*   Updated: 2024/07/02 13:33:05 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdup_2d(char **src)
{
	char	**dst;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dst = ft_calloc(i + 1, sizeof(char *));
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		if (!dst[i])
			return (ft_free_2d_arr((void **)dst), NULL);
		i++;
	}
	return (dst);
}
