/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_job_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:57:39 by akarasso          #+#    #+#             */
/*   Updated: 2018/10/16 15:06:52 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"

static void		init_signal(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGCHLD, SIG_IGN);
}

t_job_control	*init_job_control(void)
{
	t_job_control	*new;
	struct termios	tsave;

	if (!(new = ft_memalloc(sizeof(*new))))
		return (0);
	tcgetattr(STDIN_FILENO, &tsave);
	new->shell_terminal = STDIN_FILENO;
	new->shell_is_interactive = isatty(new->shell_terminal);
	if (new->shell_is_interactive)
	{
		while (tcgetpgrp(new->shell_terminal) != (new->shell_pgid = getpgrp()))
			kill(-new->shell_pgid, SIGTTIN);
		init_signal();
		new->shell_pgid = getpid();
		if (setpgid(new->shell_pgid, new->shell_pgid) < 0)
			perror("Couldn't put the shell in its own process group");
		tcsetpgrp(new->shell_terminal, new->shell_pgid);
		tcgetattr(new->shell_terminal, &new->shell_tmodes);
	}
	new->jobs = ft_dlst_new(0);
	return (new);
}
