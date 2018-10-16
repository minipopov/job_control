/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_job_in_foreground.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:58:04 by akarasso          #+#    #+#             */
/*   Updated: 2018/10/16 15:03:19 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"

void	put_job_in_foreground(t_job_control *jcontrol, t_job *job, int flag)
{
	tcsetpgrp(jcontrol->shell_terminal, job->pgid);
	if (flag)
	{
		tcsetattr(jcontrol->shell_terminal, TCSADRAIN, &job->tmodes);
		if (kill(-job->pgid, SIGCONT) < 0)
			perror("kill (SIGCONT)");
	}
	wait_for_job(jcontrol);
	tcsetpgrp(jcontrol->shell_terminal, jcontrol->shell_pgid);
	tcgetattr(jcontrol->shell_terminal, &job->tmodes);
	tcsetattr(jcontrol->shell_terminal, TCSADRAIN, &jcontrol->shell_tmodes);
}
