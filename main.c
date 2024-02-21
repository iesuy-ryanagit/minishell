/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:14:44 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/21 12:56:02 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lexparse/lex.h"
#include"builtin/built.h"
#include"execve/execve.h"
#include"handle/handle.h"
#include"base.h"

sig_atomic_t		g_signal_handled = 0;

void	start_shell(t_branch **branch, char **environ, char **line)
{
	*branch = malloc(sizeof(t_branch));
	if (branch == NULL)
	{
		printf("END\n");
		exit(EXIT_FAILURE);
	}
	(*branch)->env = make_env_list(environ, *branch);
	(*branch)->envp = environ;
	(*branch)->exit_status = 0;
	(*branch)->child_pid = NULL;
	*line = NULL;
}

int	main(int argc, char *argv[], char **environ)
{
	char				*line;
	t_branch			*branch;

	(void)argc;
	(void)argv;
	start_shell(&branch, environ, &line);
	while (1)
	{
		set_signal();
		line = readline("minishell$");
		if (g_signal_handled == 2)
			branch->exit_status = 1;
		if (line == NULL)
			exit(0);
		if (line != NULL && line[0] != '\0')
		{
			add_history(line);
			word_lexparse(line, branch);
		}
		else
			free(line);
	}
	free_env(branch->env);
	free(branch);
	return (0);
}

// void end(void)__attribute__((destructor));

// void end(void)
// {
//     system("leaks minishell");
// }
