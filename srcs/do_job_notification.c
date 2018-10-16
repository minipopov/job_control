/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_job_notification.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 13:31:35 by akarasso          #+#    #+#             */
/*   Updated: 2018/10/16 14:44:18 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"

void	do_job_notification(t_job_control *jcontrol)
{
	t_dlst_elem	*elem;

	(void)jcontrol;
	elem = jcontrol->jobs->first;
	while (elem)
	{
		elem = elem->next;
	}
}
