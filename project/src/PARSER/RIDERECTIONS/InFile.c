/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InFile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasik <hasik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:24:28 by hasik             #+#    #+#             */
/*   Updated: 2023/03/19 19:24:30 by hasik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Include/minishell.h"

void	create_infile(t_cmdlist *node, t_filelist *file)
{
	char	*pwd;
	char	ptr[256];

	if (file->metachar[1] == DOUBLE_LESS[1])
	{
		node->infile = HERADOC;
		return ;
	}
	if (raise_file_error(file, &node->infile))
		return ;
	pwd = NULL;
	own_strjoin(&pwd, (char *)getcwd(ptr, 256));
	str_addchar(&pwd, '/');
	own_strjoin(&pwd, file->filename);
	if (!access(pwd, F_OK))
		file->fd = open(pwd, O_RDONLY, 0777);
	if (file->fd <= SSTDERR && file->fd != HERADOC)
	{
		print_error("-bash: ", file->filename,
			": No such file or directory\n");
		g_core.exec_output = 1;
		file->fd = SSTDERR;
	}
	node->infile = file->fd;
	free(pwd);
}
