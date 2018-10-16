/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_process_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:13:02 by akarasso          #+#    #+#             */
/*   Updated: 2018/10/16 15:02:16 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"

int		mark_process_status_in_job(t_job *job, pid_t pid, int status)
{
	t_dlst_elem	*elem;
	t_process	*process;

	elem = job->childs->first;
	while (elem)
	{
		process = elem->data;
		if (process->pid == pid)
		{
			process->status = status;
			if (WIFSTOPPED(status))
				process->stopped = 1;
			else
			{
				process->completed = 1;
				if (WIFSIGNALED(status))
					fprintf(stderr, "%d: Terminated by signal %d.\n",
						(int)pid, WTERMSIG(process->status));
			}
			return (1);
		}
		elem = elem->next;
	}
	return (0);
}

int		mark_process_status(t_job_control *jcontrol, pid_t pid, int status)
{
	t_job		*job;
	t_dlst_elem	*elem;

	if (pid > 0)
	{
		elem = jcontrol->jobs->first;
		while (elem)
		{
			if (mark_process_status_in_job(elem->data, pid, status))
				return (0);
			job = elem->data;
		}
		return (-1);
	}
	else if (!pid || errno == ECHILD)
		return (-1);
	else
	{
		perror("waitpid");
		return (-1);
	}
}
