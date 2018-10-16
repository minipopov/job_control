/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:57:55 by akarasso          #+#    #+#             */
/*   Updated: 2018/10/16 15:04:42 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"

int	main(int argc, char **argv)
{
	t_job_control	*job_control;
	t_job			*new_job;
	t_process		*process;
	int				index;

	job_control = init_job_control();
	if (argc > 1)
	{
		new_job = init_job();
		index = 1;
		while (index < argc)
		{
			process = init_process(argv[index++]);
			ft_dlst_push(new_job->childs, process);
		}
		job_control_add(job_control, new_job);
		run_jobs(job_control, new_job);
	}
	return (0);
}
