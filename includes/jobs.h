/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:56:47 by akarasso          #+#    #+#             */
/*   Updated: 2018/10/16 14:56:49 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOBS_H
# define JOBS_H

# include <termios.h>
# include <signal.h>
# include <stdio.h>
# include <errno.h>
# include "libft.h"

typedef struct	s_process
{
	char	*bin;			/* for exec */
    pid_t	pid;			/* process ID */
    char	completed;		/* true if process has completed */
    char	stopped;		/* true if process has stopped */
    int		status;			/* reported status value */
}				t_process;

typedef struct	s_job
{
	char			*cmd;
	t_dlst			*childs;
	pid_t			pgid;
	char			notified;
	struct termios	tmodes;
	int				stdin;
	int				stdout;
	int				stderr;
	int				background;
}				t_job;

typedef	struct	s_job_control
{
	struct termios	shell_tmodes;
	t_dlst			*jobs;
	int				shell_pgid;
	int				shell_terminal;
	int				shell_is_interactive;
}				t_job_control;

t_job			*init_job();
t_process		*init_process(char *pathbin);
t_job_control	*init_job_control();
void			run_jobs(t_job_control *jcontrol, t_job *job);
int				job_control_add(t_job_control *jcontrol, t_job *new_job);
int 			exec_process(t_job *job, t_process *process, int fd[2]);
void			info_job(t_job *job, char *status);
int				is_shell_interactive();
void			mark_job_as_running(t_job *job);
int				mark_process_status(t_job_control *jcontrol, pid_t pid, int status);
void 			put_job_in_background(t_job *job, int flag);
void 			put_job_in_foreground(t_job_control *jcontrol, t_job *job, int flag);
void			continue_job(t_job_control *jcontrol, t_job *job);

#endif
