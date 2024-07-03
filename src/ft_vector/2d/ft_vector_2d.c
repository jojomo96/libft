/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz <jmoritz@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:36:55 by jmoritz           #+#    #+#             */
/*   Updated: 2024/06/20 16:55:14 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector_2d.h"
#include <math.h>
#include <stdio.h>

t_vector_2d	ft_vector_init(double x, double y)
{
	t_vector_2d	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

void	ft_print_vector(t_vector_2d vector)
{
	printf("Vector: (%f, %f)\n", vector.x, vector.y);
}

t_vector_2d	ft_vector_perpendicular(t_vector_2d vector)
{
	return (ft_vector_init(-vector.y, vector.x));
}

t_vector_2d	ft_vector_rotate(t_vector_2d vector, double angle)
{
	t_vector_2d new_vector;

	new_vector.x = vector.x * cos(angle) - vector.y * sin(angle);
	new_vector.y = vector.x * sin(angle) + vector.y * cos(angle);
	return (new_vector);
}