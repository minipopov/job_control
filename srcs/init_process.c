/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:57:46 by akarasso          #+#    #+#             */
/*   Updated: 2018/10/16 14:57:46 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"

t_process	*init_process(char *pathbin)
{
	t_process	*new;

	if (!(new = ft_memalloc(sizeof(*new))))
		return (0);
	new->bin = pathbin;
	return (new);
}
