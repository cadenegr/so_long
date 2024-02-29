/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finisher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:31:54 by cadenegr          #+#    #+#             */
/*   Updated: 2024/02/29 14:33:48 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish(t_game *g)
{
	ft_printf("Enter finish.\n");
	ft_free(g);
	ft_printf("Exit finish.\n");
	exit(EXIT_SUCCESS);
}