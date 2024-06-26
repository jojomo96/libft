/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_only.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:42:54 by lzipp             #+#    #+#             */
/*   Updated: 2024/06/26 14:07:40 by lzipp            ###   ########.fr       */
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
		while (set[j])
		{
			if (str[i] == set[j])
				;
			else if (str[i] != set[j])
				return (0);
			j++;
		}
	}
	return (1);
}
