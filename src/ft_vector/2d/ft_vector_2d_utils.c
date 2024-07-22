/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_2d_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:46:40 by jmoritz           #+#    #+#             */
/*   Updated: 2024/07/22 20:56:42 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector_2d.h"

t_vector_2d	ft_vector_add(t_vector_2d a, t_vector_2d b)
{
	t_vector_2d	vector;

	vector.x = a.x + b.x;
	vector.y = a.y + b.y;
	return (vector);
}

t_vector_2d	ft_vector_sub(t_vector_2d a, t_vector_2d b)
{
	t_vector_2d	vector;

	vector.x = a.x - b.x;
	vector.y = a.y - b.y;
	return (vector);
}

t_vector_2d	ft_vector_mul(t_vector_2d a, t_vector_2d b)
{
	t_vector_2d	vector;

	vector.x = a.x * b.x;
	vector.y = a.y * b.y;
	return (vector);
}

t_vector_2d	ft_vector_div(t_vector_2d a, t_vector_2d b)
{
	t_vector_2d	vector;

	if (b.x == 0 || b.y == 0)
	{
		vector.x = 0;
		vector.y = 0;
	}
	else
	{
		vector.x = a.x / b.x;
		vector.y = a.y / b.y;
	}
	return (vector);
}

t_vector_2d	ft_vector_scale(t_vector_2d a, double scale)
{
	t_vector_2d	vector;

	vector.x = a.x * scale;
	vector.y = a.y * scale;
	return (vector);
}
