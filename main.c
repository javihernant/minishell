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

void	ft_skip_other_tk(char *cmd, int *idx, char find);
void	ft_skip_slash(char *cmd, int *idx);

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

/*
int	ft_find_op_idx(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != '(' && cmd[i] != ')'
		&& cmd[i] != '\0' && !ft_is_op(cmd, i))
	{
		i++;
	}
	if (cmd[i] == ')')
	{
		printf("Syntax error: Found ) before (");
		return (-1);
	}
	if (cmd[i] == '(')
		ft_skip_par(cmd, &i);
	while (ft_isspace(cmd[i]))
		i++;
	if (ft_is_op(cmd, i))
		return (i);
	else if (cmd[i] != '\0')
		printf("Syntax error: expected an operator\n");
	return (-1);
}
*/

int	ft_is_token(char c)
{
	return (c == '\\' || c == '(' || c == '\'' || c == '"');
}

char	ft_closing_token(char tk)
{
	if (tk == '(')
		return (')');
	else if (tk == '\'')
		return ('\'');
	else if (tk == '"')
		return ('"');
	return ('\0');
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

//TODO: (")")
//(()ignore)
//(\))
//"()"
//(a) c  && b
//prog "(" && ( a && b)
//("\)") && b

int	ft_find_op_idx(char *cmd)
{
	int	i;

	i = 0;
	while (1)
	{
		while (!ft_is_token(cmd[i]) && cmd[i] != ')' && !ft_is_op(cmd, i) && cmd[i] != '\0')		
		{
			i++;
		}
		if (ft_is_token(cmd[i]))
		{
			ft_skip_token(cmd, &i);
		}
		else if (cmd[i] == ')')
		{
			printf("Found closing token (%c) before open one\n", cmd[i]);
			return (-1);
		}
		else
			break;
	}
	if (ft_is_op(cmd, i))
		return (i);
	else
		return (-1);
}

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
