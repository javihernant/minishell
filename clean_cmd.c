/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:25:59 by jahernan          #+#    #+#             */
/*   Updated: 2023/02/01 11:34:41 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean_cmd.h"
#include "libft.h"

static int	ft_cnt_open_par(char *cmd_ln)
{
	int	open_cnt;
	int		i;

	i = 0;
	open_cnt = 0;
	while (1)
	{
		while (ft_isspace(cmd_ln[i]))
		{
			i++;
		}
		if (cmd_ln[i] == '(')
		{
			i++;
			open_cnt++;
		}
		else
			break ;
	}
	return (open_cnt);
}

static int	ft_cnt_close_par(char *cmd_ln)
{
	int	i;
	int	close_cnt;

	i = ft_strlen(cmd_ln) - 1;
	close_cnt = 0;
	while (i >= 0)
	{
		while (i > 0 && ft_isspace(cmd_ln[i]))
		{
			i--;
		}
		if (cmd_ln[i] == ')')
		{
			i--;
			close_cnt++;
		}
		else
			break ;
	}
	return (close_cnt);
}

int	ft_cnt_redundant_pars(char *cmd_ln)
{
	int	open_cnt;
	int	close_cnt;

	open_cnt = ft_cnt_open_par(cmd_ln);
	close_cnt = ft_cnt_close_par(cmd_ln);
	return (ft_min(open_cnt, close_cnt));
}

char	*ft_rm_pars(char *cmd_ln, int pars_cnt)
{
	int	i;
	int	j;

	i = ft_begin_no_par_idx(cmd_ln, pars_cnt);
	j = ft_end_no_par_idx(cmd_ln, pars_cnt);
	return (ft_strcpy_range(cmd_ln, i, j));
}

/* Returns a newly allocated string that contains no redundant parentheses. (i.e `((a && b))` would become `a && b`. `((a && b) && c)` to `(a && b) && c` */
char	*ft_cpy_cmd_clean(char *cmd_ln)
{
	int		pars_cnt;
	char	*str;

	pars_cnt = ft_cnt_redundant_pars(cmd_ln);
	str = ft_rm_pars(cmd_ln, pars_cnt);
	return (str);
}
