/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_only.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:42:54 by lzipp             #+#    #+#             */
/*   Updated: 2024/06/27 16:10:10 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_contains_only(const char *str, const char *set)
{
	int		i;
	int		j;
	
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (set[++j])
		{
			if (str[i] == set[j])
				break ;
		}
		if (!set[j])
			return (0);
	}
	return (1);
}
