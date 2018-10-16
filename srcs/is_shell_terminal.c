/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shell_terminal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:57:49 by akarasso          #+#    #+#             */
/*   Updated: 2018/10/16 15:07:39 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"

int	is_shell_interactive(void)
{
	int shell_terminal;

	shell_terminal = STDIN_FILENO;
	return (isatty(shell_terminal));
}
