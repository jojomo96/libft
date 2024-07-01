/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_in_place.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:16:18 by vscode            #+#    #+#             */
/*   Updated: 2024/07/01 18:12:39 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Joins s2 to the end of s1.
 * @param s1 The first string.
 * @param s2 The second string.
 * @return The new string.
 */
char	*ft_strjoin_in_place(char *s1, const char *s2)
{
	char	*result;

	result = ft_strjoin_better(s1, s2);
	free(s1);
	return (result);
}
