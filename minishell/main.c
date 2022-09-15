/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:33 by tiwai             #+#    #+#             */
/*   Updated: 2021/05/18 23:07:47 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"
#include "./includes/type.h"

int	g_status;

static int	parce_and_exec(char *line, t_shell *shell)
{
	t_token	*token_list;
	t_ast	*ast;
	int		loop;

	loop = 1;
	start_tokenizer(line, &token_list, ft_strlen(line));
	if (token_empty(&token_list))
		return (loop);
	if (!check_quote_token(token_list))
	{
		token_lstclear(&token_list);
		return (loop);
	}
	if (parcer(token_list, &ast))
	{
		make_cmd_table(ast, token_lstsize(token_list));
		loop = executer(ast, shell);
	}
	token_lstclear(&token_list);
	ast_clear(&ast);
	return (loop);
}

static void	minishell_loop(char *hist_path, t_shell *shell)
{
	char	*line;
	int		loop;

	loop = 1;
	while (loop)
	{
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, sigquit_handler);
		line = start_reading(hist_path);
		if (line == NULL)
			break ;
		if (ft_strlen(line) == 0)
		{
			free(line);
			continue ;
		}
		loop = parce_and_exec(line, shell);
		free(line);
	}
}

static char	*get_histpath(void)
{
	static char	*path;
	char		*current;
	char		*done;

	if (path == NULL)
	{
		current = getcwd(NULL, 0);
		path = safe_join(current, "/");
		free(current);
		done = path;
		path = safe_join(path, "minishell_history");
		free(done);
	}
	return (path);
}

static void	handle_shellvar(t_shell *shell, int delete)
{
	int	i;

	if (delete)
	{
		safe_free(&(shell->oldpwd));
		safe_free(&(shell->pwd));
		free_multi(&(shell->env_arr));
		env_lstclear(&(shell->envlist));
		return ;
	}
	shell->oldpwd = NULL;
	shell->pwd = getcwd(NULL, 0);
	shell->env_arr = NULL;
	shell->pipe = false;
	shell->on_pwd = true;
	i = 0;
	while (i <= FD_MAX)
		shell->usedfd[i++] = -1;
}

int	main(int argc, char **argv, char *envv[])
{
	t_env	*env;
	char	*hist_pass;
	t_shell	shell;

	handle_shellvar(&shell, INITSHELL);
	g_status = 0;
	env_copy(&env, envv);
	list_mergesort(&env);
	shell.envlist = env;
	hist_pass = get_histpath();
	if (argc > 2 && ft_strncmp("-c", argv[1], 3) == 0)
		parce_and_exec(argv[2], &shell);
	else
		minishell_loop(hist_pass, &shell);
	free(hist_pass);
	handle_shellvar(&shell, DELETESHELL);
	return (g_status);
}
