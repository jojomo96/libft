/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:38:17 by lzipp             #+#    #+#             */
/*   Updated: 2024/06/28 10:45:27 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_2d_arr(void **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	ft_free_3d_arr(void ***arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		ft_free_2d_arr(arr[i]);
	free(arr);
}

void	ft_free_4d_arr(void ****arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		ft_free_3d_arr(arr[i]);
	free(arr);
}
