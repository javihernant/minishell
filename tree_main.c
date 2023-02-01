#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "types.h"
#include "libft.h"
#include "shell_utils.h"

//TODO: (")")
//(()ignore)
//(\))
//"()"
//(a) c  && b
//prog "(" && ( a && b)
//("\)") && b

/*
t_cmdtree	*ft_build_cmdtree(char *cmd_ln)
{
	t_cmdtree	*tree;
	char		*left_cmd;
	char		*right_cmd;
	int			op_idx;

	tree = malloc(sizeof(t_cmdtree));
	tree->children = NULL;
	tree->cmd = ft_cpy_cmd_clean(cmd_ln);
	tree->type = ft_find_op_idx(tree->cmd, &op_idx);
	if (tree->type == ft_tree_type(tree->cmd[op_idx]))
		return (tree);
	tree->children = malloc(sizeof(t_cmdtree) * 2);
	if (!tree->children)
		return (NULL);
	left_cmd = ft_strcpy_range(tree->cmd, 0, op_idx);
	tree->children[0] = ft_build_cmdtree(left_cmd);
	right_cmd = ft_strcpy_range(tree->cmd, op_idx + 2, ft_strlen(tree->cmd));
	tree->children[1] = ft_build_cmdtree(right_cmd);
	free(left_cmd);
	free(right_cmd);
	return (tree);
}
*/

int	main()
{
	char		*command_ln;
	char		*clean_cmd;
	//t_cmdtree	*tree;
	int	i = 0;
	while (1)
	{
		printf(">");
		command_ln = readline(NULL);
		clean_cmd = ft_cpy_cmd_clean(command_ln);
		printf("%s\n", clean_cmd);
		i = ft_find_op_idx(clean_cmd);
		printf("op_idx: %d\n", i);
		i = 0;
		//tree = ft_build_cmdtree(command_ln);
		//ft_exec_cmdtree(&tree);
		//ft_free_cmdtree(&tree);
		free(command_ln);
		free(clean_cmd);
	}
	return (0);
}
