/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_control_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:51:04 by akarasso          #+#    #+#             */
/*   Updated: 2018/10/16 14:52:23 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"

int		job_control_add(t_job_control *jcontrol, t_job *new_job)
{
	if (!ft_dlst_push(jcontrol->jobs, new_job))
		return (0);
	return (1);
}
