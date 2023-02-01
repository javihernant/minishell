/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_operator_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:59:31 by jahernan          #+#    #+#             */
/*   Updated: 2023/02/01 12:03:55 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_skip_slash(char *cmd, int *idx)
{
	if (cmd[*idx] != '\\')
		return ;
	if (cmd[*idx + 1] == '\0')
		*idx += 1;
	else
		*idx += 2;
}

void	ft_skip_other_tk(char *cmd, int *idx, char find)
{
	int	i;

	i = *idx + 1;
	while (cmd[i] != '\0' && cmd[i] != find)
	{
		if (cmd[i] == '\\')
			ft_skip_slash(cmd, &i);
		else
			i++;
	}
	if (cmd[i] == '\0')
	{
		*idx = i;
		printf("No ending token was found for %c\n", find);
		return ;
	}
	*idx = i + 1;
}

void	ft_count_next_par(char *cmd, int *idx, int *pars_cnt)
{
	int	i;

	i = *idx;
	while (cmd[i] != '(' && cmd[i] != ')' && cmd[i] != '\0')
	{
		if (cmd[i] == '\\')
			ft_skip_slash(cmd, &i);
		else if (cmd[i] == '\'' || cmd[i] == '"')
			ft_skip_other_tk(cmd, &i, cmd[i]);
		else
			i++;
	}
	if (cmd[i] == '(')
		(*pars_cnt)++;
	if (cmd[i] == ')')
		(*pars_cnt)--;
	*idx = i;
}

void	ft_skip_par(char *cmd, int *idx)
{
	int	i;	
	int	pars_cnt;	

	i = *idx;
	if (cmd[i] != '(')
		return ;
	i++;
	pars_cnt = 1;
	while (1)
	{
		ft_count_next_par(cmd, &i, &pars_cnt);
		if (pars_cnt == 0)
		{
			i++;
			break ;
		}
		if (cmd[i] == '\0' && pars_cnt != 0)
		{
			printf("Parenthesis mismatch!\n");
			return ;
		}
		i++;
	}
	*idx = i;
}

void	ft_skip_token(char *cmd, int *idx)
{
	char	tk;

	tk = cmd[*idx];
	if (tk == '\\')
		ft_skip_slash(cmd, idx);
	else if (tk == '(')
		ft_skip_par(cmd, idx);
	else if (tk == '\'' || tk == '"')
		ft_skip_other_tk(cmd, idx, tk);
}
