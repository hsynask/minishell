/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StrCompare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasik <hasik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:23:39 by hasik             #+#    #+#             */
/*   Updated: 2023/03/19 19:23:42 by hasik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Include/minishell.h"

int	str_compare(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (0);
	while (*str1)
	{
		if (*str1 != *str2)
			break ;
		str1++;
		str2++;
	}
	if (*str1 != 0 || *str2 != 0)
		return (0);
	return (1);
}
