/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CreateFiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasik <hasik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:24:17 by hasik             #+#    #+#             */
/*   Updated: 2023/03/19 19:24:18 by hasik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Include/minishell.h"

void	create_files(t_cmdlist *node)
{
	t_filelist	*temp_file;

	if (!node)
		return ;
	run_heradocs(node);
	if (g_core.exec_output || !node)
		return ;
	while (node)
	{
		temp_file = node->files;
		while (temp_file)
		{
			if (*temp_file->metachar == *SINGLE_GREAT)
				create_outfile(node, temp_file);
			else
				create_infile(node, temp_file);
			if (temp_file->fd == SSTDERR)
			{
				g_core.exec_output = 1;
				break ;
			}
			temp_file = temp_file->next;
		}
		node = node->next;
	}
}
