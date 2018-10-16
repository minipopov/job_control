/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:57:36 by akarasso          #+#    #+#             */
/*   Updated: 2018/10/16 15:08:06 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"

void	info_job(t_job *job, char *status)
{
	fprintf(stderr, "%ld (%s): %s\n", (long)job->pgid, status, job->cmd);
}
