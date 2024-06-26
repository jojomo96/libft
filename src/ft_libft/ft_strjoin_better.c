/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_better.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:23:01 by lzipp             #+#    #+#             */
/*   Updated: 2024/06/26 14:34:18 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates and returns a new string, which is the result of the concatenation
 * of 's1' and 's2'. If one string is NULL, the other is returned.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return   The new string. NULL if the allocation fails.
 */
char	*ft_strjoin_better(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc(s1_len + s2_len + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcat(new_str, s2, s1_len + s2_len + 1);
	return (new_str);
}
