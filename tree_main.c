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

int	ft_tree_type(char *cmd, int op_idx)
{
	if (op_idx == -1)
		return (T_LEAF);
	else if (cmd[op_idx] == '|')
		return (T_OR);
	else if (cmd[op_idx] == '&')
		return (T_AND);
	else
	{
		printf("%c%c is not a valid operator!\n", cmd[op_idx], cmd[op_idx + 1]);
		return (T_ERROR);
	}
}

/*
int	ft_malloc_children(t_cmdtree *tree)
{
	tree->left = malloc(sizeof(t_cmdtree));
	if (tree->left == NULL)
		return (1);
	tree->right = malloc(sizeof(t_cmdtree));
	if (!tree->right)
	{
		free (tree->left);
		tree->left = NULL;
		return (1);
	}
	return (0);
}
*/

t_cmdtree	*ft_build_cmdtree(char *cmd_ln)
{
	t_cmdtree	*tree;
	char		*left_cmd;
	char		*right_cmd;
	int			op_idx;

	tree = malloc(sizeof(t_cmdtree));
	tree->cmd = ft_cpy_cmd_clean(cmd_ln);
	free(cmd_ln);
	op_idx = ft_find_op_idx(tree->cmd);
	tree->type = ft_tree_type(tree->cmd, op_idx);
	if (tree->type == T_LEAF)
		return (tree);
	left_cmd = ft_strcpy_range(tree->cmd, 0, op_idx);
	tree->left = ft_build_cmdtree(left_cmd);
	right_cmd = ft_strcpy_range(tree->cmd, op_idx + 2, ft_strlen(tree->cmd));
	tree->right = ft_build_cmdtree(right_cmd);
	return (tree);
}

void	ft_exec_cmdtree(t_cmdtree *tree)
{
	if (tree->type == T_LEAF)
	{
		printf("%s\n", tree->cmd);
	}
	else
	{
		printf("%s\n", tree->cmd);
		ft_exec_cmdtree(tree->left);
		ft_exec_cmdtree(tree->right);
	}
	free(tree->cmd);
	free(tree);
}

int	main()
{
	char		*command_ln;
	t_cmdtree	*tree;
	while (1)
	{
		printf(">");
		command_ln = readline(NULL);
		tree = ft_build_cmdtree(command_ln);
		ft_exec_cmdtree(tree);
		//ft_free_cmdtree(&tree);
	}
	return (0);
}
