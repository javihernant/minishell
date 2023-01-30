/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:43:49 by jahernan          #+#    #+#             */
/*   Updated: 2023/01/26 13:30:45 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define T_LEAF 0
# define T_OR 1
# define T_AND 2

typedef struct s_cmdtree
{
	int					type;
	int					rc;
	struct s_cmdtree	children[2];
	char				*cmd;
}	t_cmdtree;

ft_build_cmdtree(char *cmd);
#endif
