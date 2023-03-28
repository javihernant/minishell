/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atalaver <atalaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:43:49 by jahernan          #+#    #+#             */
/*   Updated: 2023/03/27 17:25:41 by atalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include "libft.h"
# include "shell_utils.h"

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
void		ft_exec_cmdtree(t_cmdtree *tree, char *path);
void		ft_free_cmdtree(t_cmdtree *tree);
#endif
