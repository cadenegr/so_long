/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:40:42 by cadenegr          #+#    #+#             */
/*   Updated: 2024/02/29 16:52:59 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(int type)
{
	ft_printf("XXXXXX-Enter ft error.\n");
	if (type == 1)
		ft_putstr_fd("Error\nWrong file!\n", 2);
	if (type == 2)
		ft_putstr_fd("Error\nFile invalid!\n", 2);
	if (type == 3)
		ft_putstr_fd("Error\nMap size is invalid!\n", 2);
	if (type == 4)
		ft_putstr_fd("Error\nInvalid map parameters!\n", 2);
	if (type == 5)
		ft_putstr_fd("Error\nNo player or exit in map!\n", 2);
	if (type == 6)
		ft_putstr_fd("Error\nNo collectabiles!\n", 2);
	if (type == 7)
		ft_putstr_fd("Error\nMap counldn't load!\n", 2);
	if (type == 8)
		ft_putstr_fd("Error\nInvalid path!\n", 2);
	if (type == 9)
		ft_putstr_fd("Error\nWindow can't open!\n", 2);
	ft_printf("XXXXXX-Exit ft error.\n");
	return (0);
}