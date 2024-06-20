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
#include <stdio.h>

t_vector_2d    ft_vector_init(double x, double y)
{
    t_vector_2d    vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

void    ft_print_vector(t_vector_2d vector)
{
    printf("Vector: (%f, %f)\n", vector.x, vector.y);
}