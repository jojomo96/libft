/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:56:25 by lzipp             #+#    #+#             */
/*   Updated: 2024/06/20 17:00:39 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compares at most the last 'n' characters of two strings 's1' and 's2'.
 *
 * @param s1 The first string to be compared.
 * @param s2 The second string to be compared.
 * @param n The maximum number of characters to compare.
 * @return An integer greater than, equal to, or less than 0,
 *	depending on the comparison result.
 *	- A value greater than 0 indicates that the last 'n' characters of 's1'
 *			are greater than the last 'n' characters of 's2'.
 *	- A value less than 0 indicates that the last 'n' characters of 's1' are
 *			less than the last 'n' characters of 's2'.
 *	- A value of 0 indicates that the last 'n' characters of 's1' are equal
 *		to the last 'n' characters of 's2'.
 */
int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	int			ind1;
	int			ind2;

	if (!s1 || !s2 || n == 0)
		return (0);
	ind1 = ft_strlen(s1) - 1;
	ind2 = ft_strlen(s2) - 1;
	while (n && s1[ind1] && (s1[ind1] == s2[ind2]))
	{
		if (n > 1)
		{
			--ind1;
			--ind2;
		}
		--n;
	}
	return ((int)(*(unsigned char *)&s1[ind1] - *(unsigned char *)&s2[ind2]));
}
