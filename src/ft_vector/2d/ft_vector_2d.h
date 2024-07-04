/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_2d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz <jmoritz@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:34:48 by jmoritz           #+#    #+#             */
/*   Updated: 2024/06/20 17:02:20 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_2D_H
# define FT_VECTOR_2D_H

typedef struct s_vector_2d
{
	double	x;
	double	y;
}			t_vector_2d;

t_vector_2d	ft_vector_init(double x, double y);
t_vector_2d	ft_vector_add(t_vector_2d a, t_vector_2d b);
t_vector_2d	ft_vector_sub(t_vector_2d a, t_vector_2d b);
t_vector_2d	ft_vector_mul(t_vector_2d a, t_vector_2d b);
t_vector_2d	ft_vector_div(t_vector_2d a, t_vector_2d b);
t_vector_2d	ft_vector_scale(t_vector_2d a, double scale);
t_vector_2d	ft_vector_rotate(t_vector_2d vector, double angle);
t_vector_2d	ft_vector_perpendicular(t_vector_2d vector);
void		ft_print_vector(t_vector_2d vector);

#endif
