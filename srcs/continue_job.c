/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continue_job.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 13:27:00 by akarasso          #+#    #+#             */
/*   Updated: 2018/10/16 15:08:15 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"

void	continue_job(t_job_control *jcontrol, t_job *job)
{
	mark_job_as_running(job);
	if (job->background)
		put_job_in_background(job, 1);
	else
		put_job_in_foreground(jcontrol, job, 1);
}
