/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClearEmptyContent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasik <hasik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:26:51 by hasik             #+#    #+#             */
/*   Updated: 2023/03/19 19:26:53 by hasik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Include/minishell.h"

void	clear_void_contents(void)
{
	t_lexlist	*lex_list;
	t_lexlist	*temp_lex_list;

	lex_list = g_core.lex_table;
	temp_lex_list = g_core.lex_table;
	while (lex_list)
	{
		if (!lex_list->content)
		{
			if (lex_list == g_core.lex_table)
			{
				g_core.lex_table = g_core.lex_table->next;
				temp_lex_list = temp_lex_list->next;
			}
			else
				temp_lex_list->next = lex_list->next;
			free(lex_list);
			lex_list = temp_lex_list;
		}
		temp_lex_list = lex_list;
		if (lex_list)
			lex_list = lex_list->next;
	}
}
