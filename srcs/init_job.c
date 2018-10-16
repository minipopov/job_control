/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:57:43 by akarasso          #+#    #+#             */
/*   Updated: 2018/10/16 15:07:47 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"

t_job	*init_job(void)
{
	t_job	*new;

	if (!(new = ft_memalloc(sizeof(*new))))
		return (0);
	new->childs = ft_dlst_new(0);
	new->stdin = 0;
	new->stdout = 1;
	new->stderr = 2;
	return (new);
}
