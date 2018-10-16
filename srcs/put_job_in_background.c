/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_job_in_background.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:58:01 by akarasso          #+#    #+#             */
/*   Updated: 2018/10/16 15:04:59 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"

void	put_job_in_background(t_job *job, int flag)
{
	if (flag && kill(-job->pgid, SIGCONT) < 0)
		perror("kill (SIGCONT)");
}
