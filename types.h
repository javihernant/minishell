/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:43:49 by jahernan          #+#    #+#             */
/*   Updated: 2023/02/01 12:37:18 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define T_LEAF 0
# define T_OR 1
# define T_AND 2
# define T_ERROR 3

typedef struct s_cmdtree {
	int					type;
	int					rc;
	struct s_cmdtree	*left;
	struct s_cmdtree	*right;
	char				*cmd;
}	t_cmdtree;

t_cmdtree	*ft_build_cmdtree(char *cmd);
#endif
