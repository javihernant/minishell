/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_cmd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:30:07 by jahernan          #+#    #+#             */
/*   Updated: 2023/02/01 11:33:17 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_begin_no_par_idx(char *cmd_ln, int pars_cnt)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (c < pars_cnt)
	{
		while (cmd_ln[i] != '(')
		{
			i++;
		}
		i++;
		c++;
	}
	return (i);
}

int	ft_end_no_par_idx(char *cmd_ln, int pars_cnt)
{
	int	j;
	int	c;

	c = 0;
	j = ft_strlen(cmd_ln) - 1;
	while (c < pars_cnt)
	{
		while (cmd_ln[j] != ')')
		{
			j--;
		}
		j--;
		c++;
	}
	return (j + 1);
}
