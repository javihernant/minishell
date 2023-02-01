/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:04:29 by jahernan          #+#    #+#             */
/*   Updated: 2023/02/01 12:12:03 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "find_operator.h"

int	ft_is_op(char *str, int i)
{
	char	*s;

	s = &str[i];
	if (ft_strlen(s) < 2)
		return (0);
	if (ft_strncmp(s, "&&", 2) == 0
		|| ft_strncmp(s, "||", 2) == 0)
	{
		return (1);
	}
	return (0);
}

int	ft_is_token(char c)
{
	return (c == '\\' || c == '(' || c == ')' || c == '\'' || c == '"');
}

int	ft_find_op_idx(char *cmd)
{
	int	i;

	i = 0;
	while (1)
	{
		while (!ft_is_token(cmd[i]) && !ft_is_op(cmd, i) && cmd[i] != '\0')		
		{
			i++;
		}
		if (cmd[i] == ')')
		{
			printf("Found closing token (%c) before open one\n", cmd[i]);
			return (-1);
		}
		else if (ft_is_token(cmd[i]))
		{
			ft_skip_token(cmd, &i);
		}
		else
			break ;
	}
	if (ft_is_op(cmd, i))
		return (i);
	else
		return (-1);
}
