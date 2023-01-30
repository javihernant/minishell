#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "types.h"
#include "libft.h"

/* Look for && or ||. If neither can be found, then there's only one command. */
/*
int	ft_is_one_cmd(char *cmd_ln)
{
	return (0);
}
*/

//TODO
/* Finds the first operator's index (Looks only in the outest level. In other words, if it finds a parentheses it ignores everything inside it). Uses it to create a copy of a portion of cmd_ln. */
/*
char	*ft_left_child_cmd(char *cmd_ln)
{
	int	i;

	i = 0;
	while ()
	{
		i++;
	}
	return (ft_copy_str(cmd_ln, 0, i));
}
*/

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

//TODO: add ft_min libft
int	ft_cnt_redundant_pars(char *cmd_ln)
{
	int	open_cnt;
	int	close_cnt;

	open_cnt = ft_cnt_open_par(cmd_ln);
	close_cnt = ft_cnt_close_par(cmd_ln);
	return (ft_min(open_cnt, close_cnt));
}

static int	ft_begin_no_par_idx(char *cmd_ln, int pars_cnt)
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

static int	ft_end_no_par_idx(char *cmd_ln, int pars_cnt)
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

char	*ft_rm_pars(char *cmd_ln, int pars_cnt)
{
	int	i;
	int	j;

	i = ft_begin_no_par_idx(cmd_ln, pars_cnt);
	j = ft_end_no_par_idx(cmd_ln, pars_cnt);
	printf("i: %d, j: %d\n", i, j);
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

/*
t_cmdtree	*ft_build_cmdtree(char *cmd_ln)
{
	t_cmdtree	*tree;
	char		*left_cmd;
	char		*right_cmd;

	tree = malloc(sizeof(t_cmdtree));
	tree->children = NULL;
	tree->cmd = ft_cpy_cmd_clean(cmd_ln);
	tree->type = ft_get_tree_type(tree->cmd);
	if (tree->type == T_LEAF)
		return (tree);
	tree->children = malloc(sizeof(t_cmdtree) * 2);
	if (!tree->children)
		return (NULL);
	left_cmd = ft_left_child_cmd(cmd_ln);
	tree->children[0] = ft_build_cmdtree(left_cmd);
	right_cmd = ft_right_child_cmd(cmd_ln);
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
	while (1)
	{
		printf(">");
		command_ln = readline(NULL);
		clean_cmd = ft_cpy_cmd_clean(command_ln);

		printf("%s\n", clean_cmd);
		printf("%d\n", ft_cnt_redundant_pars(command_ln));
		//tree = ft_build_cmdtree(command_ln);
		//ft_exec_cmdtree(&tree);
		//ft_free_cmdtree(&tree);
		free(command_ln);
		free(clean_cmd);
	}
	return (0);
}
