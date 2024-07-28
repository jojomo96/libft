/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_2d_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:01:36 by jmoritz           #+#    #+#             */
/*   Updated: 2024/07/28 11:03:16 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector_2d.h"
#include <math.h>

double	ft_vector_length(t_vector_2d vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y));
}

t_vector_2d	ft_vector_normalize(t_vector_2d vector)
{
	double		length;
	t_vector_2d	normalized;

	length = ft_vector_length(vector);
	if (length == 0)
		return (ft_vector_init(0, 0));
	normalized.x = vector.x / length;
	normalized.y = vector.y / length;
	return (normalized);
}
