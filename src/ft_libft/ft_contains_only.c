/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_only.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:42:54 by lzipp             #+#    #+#             */
/*   Updated: 2024/06/26 14:17:23 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_contains_only(const char *str, const char *set)
{
	int		i;
	int		j;
	int		found;

	i = 0;
	while (str[i])
	{
		j = 0;
		found = 0;
		while (set[j])
		{
			if (str[i] == set[j])
			{
				found = 1;
				break;
			}
			j++;
		}
		if (!found)
			return (0);
		i++;
	}
	return (1);
}
