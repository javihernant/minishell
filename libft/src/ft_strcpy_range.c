/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:58:46 by jahernan          #+#    #+#             */
/*   Updated: 2023/01/30 20:55:04 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy_range(char *str, int i, int j)
{
	char	*copy;
	int		k;

	copy = malloc(j - i);
	k = 0;
	while (i < j)
	{
		copy[k] = str[i];
		k++;
		i++;
	}
	copy[k] = '\0';
	return (copy);
}
