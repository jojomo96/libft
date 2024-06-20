/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_2d_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz <jmoritz@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:46:40 by jmoritz           #+#    #+#             */
/*   Updated: 2024/06/20 16:53:48 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector_2d.h"

t_vector_2d    ft_vector_add(t_vector_2d a, t_vector_2d b)
{
    t_vector_2d    vector;

    vector.x = a.x + b.x;
    vector.y = a.y + b.y;
    return (vector);
}

t_vector_2d    ft_vector_sub(t_vector_2d a, t_vector_2d b)
{
    t_vector_2d    vector;

    vector.x = a.x - b.x;
    vector.y = a.y - b.y;
    return (vector);
}

t_vector_2d    ft_vector_mul(t_vector_2d a, t_vector_2d b)
{
    t_vector_2d    vector;

    vector.x = a.x * b.x;
    vector.y = a.y * b.y;
    return (vector);
}

t_vector_2d    ft_vector_div(t_vector_2d a, t_vector_2d b)
{
    t_vector_2d    vector;

    vector.x = a.x / b.x;
    vector.y = a.y / b.y;
    return (vector);
}

t_vector_2d    ft_vector_scale(t_vector_2d a, double scale)
{
    t_vector_2d    vector;

    vector.x = a.x * scale;
    vector.y = a.y * scale;
    return (vector);
}
