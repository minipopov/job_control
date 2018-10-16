/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_job_as_running.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 13:28:17 by akarasso          #+#    #+#             */
/*   Updated: 2018/10/16 15:04:13 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"

void	mark_job_as_running(t_job *job)
{
	t_dlst_elem	*elem;
	t_process	*process;

	elem = job->childs->first;
	while (elem)
	{
		process = elem->data;
		process->stopped = 0;
		elem = elem->next;
	}
	job->notified = 0;
}
