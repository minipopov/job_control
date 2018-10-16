/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:57:32 by akarasso          #+#    #+#             */
/*   Updated: 2018/10/16 15:07:28 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"

static void	setup_output(t_job *job, int fd[2])
{
	if (fd[0] != STDIN_FILENO)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	if (fd[1] != STDOUT_FILENO)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
	if (job->stderr != STDERR_FILENO)
	{
		dup2(job->stderr, STDERR_FILENO);
		close(job->stderr);
	}
}

/*
**	SIGINT	<=>	Sinal d'arret du process par un ctrl + C
**	SIGQUIT	<=>	Sinal d'arret du process par un process extern
**	SIGTSTP	<=>	Sinal stop du process
**	SIGTTIN	<=>	Sinal background job tries to read from the terminal
**	SIGTTOU	<=>	Sinal when background job attempts to write to the
**				terminal or set its modes
**	SIGCHLD	<=>	Sinal sent to a parent process whenever one of
**				its child processes terminates or stops
*/

int			exec_process(t_job *job, t_process *process, int fd[2])
{
	pid_t	pid;

	pid = getpid();
	if (!job->pgid)
	{
		if (setpgid(pid, job->pgid) < 0)
		{
			printf("Error setpgid");
			exit(1);
		}
	}
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGTTIN, SIG_DFL);
	signal(SIGTTOU, SIG_DFL);
	signal(SIGCHLD, SIG_DFL);
	setup_output(job, fd);
	execve(process->bin, (char*[2]){process->bin, 0}, 0);
	exit(1);
}
