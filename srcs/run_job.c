/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_job.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:58:07 by akarasso          #+#    #+#             */
/*   Updated: 2018/10/16 15:00:12 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"

int		set_fd(t_job *job, int pipefd[2], int fd[2], t_dlst_elem *elem)
{
	if (elem->next)
	{
		if (pipe(pipefd) < 0)
			return (0);
		fd[1] = pipefd[1];
	}
	else
		fd[1] = job->stdout;
	return (1);
}

int		run_process(t_job *job, t_process *process, int pipefd[2], int fd[2])
{
	pid_t		forkpid;

	if ((forkpid = fork()) < 0)
		return (0);
	if (!forkpid)
		exit(exec_process(job, process, fd));
	else
	{
		process->pid = forkpid;
		if (!job->pgid)
			job->pgid = forkpid;
		if (setpgid(forkpid, job->pgid) < 0)
		{
			printf("Error setpgid");
			exit(1);
		}
	}
	if (fd[0] != job->stdin)
		close(fd[0]);
	if (fd[1] != job->stdout)
		close(fd[1]);
	fd[0] = pipefd[0];
	return (1);
}

void	run_jobs(t_job_control *jcontrol, t_job *job)
{
	t_dlst_elem	*elem;
	int			pipefd[2];
	int			fd[2];
	int			status;

	elem = job->childs->first;
	while (elem)
	{
		if (!set_fd(job, pipefd, fd, elem))
		{
			perror("pipe");
			exit(1);
		}
		run_process(job, elem->data, pipefd, fd);
		elem = elem->next;
	}
	info_job(job, "Launched");
	waitpid(WAIT_ANY, &status, WUNTRACED);
	if (!is_shell_interactive())
		wait_for_job(jcontrol);
	else if (job->background)
		put_job_in_background(job, 0);
	else
		put_job_in_foreground(jcontrol, job, 0);
}
