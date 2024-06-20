/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_in_place.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:43:35 by lzipp             #+#    #+#             */
/*   Updated: 2024/06/20 16:47:33 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Removes leading and trailing characters specified in the 'set' parameter from
 * the string 's1'.
 *
 * @param s1 The string to be trimmed.
 * @param set The set of characters to be removed.
 * @return The same string with leading and trailing characters removed,
 *         or NULL if memory allocation fails.
 */
char	*ft_strtrim_in_place(char *str, char const *set)
{
	char	*result;

	if (!str || !set)
		return (NULL);
	result = ft_strtrim(str, set);
	free(str);
	return (result);
}
