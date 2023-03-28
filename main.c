/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atalaver <atalaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:11:19 by atalaver          #+#    #+#             */
/*   Updated: 2023/03/27 17:27:34 by atalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	control_c(int n)
{
	rl_replace_line("", 1);
	rl_on_new_line();
	printf("\n>");
	signal(n, control_c);
}

int	main(void)
{
	char		*command_ln;
	t_cmdtree	*tree;
	char		path[1024];

	signal(SIGINT, control_c);
	signal(SIGQUIT, SIG_IGN);
	getcwd(path, 1024);
	printf("PATH: %s\n", path);
	while (1)
	{
		printf(">");
		command_ln = readline(NULL);
		if (!command_ln)
			break ;
		tree = ft_build_cmdtree(command_ln);
		ft_exec_cmdtree(tree, path);
		ft_free_cmdtree(tree);
	}
	return (0);
}
