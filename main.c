/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:15:41 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/16 15:23:17 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "network/ptri_network.h"
#include "network/utils/ft_split/ft_split.h"
#include <string.h>
#include <assert.h>


int	main(void)
{
    t_petri_network	*network_1;
	
	int	pt[2];
	char	*m0 = strdup("1 0 0 1");
	char	*m_out = strdup("1 0 0 0 1 0 0 0 3 0 1 0");
	char	*m_int = strdup("1 0 0 0 1 0 0 0 3 0 1 0");
	
	pt[0] = 4;
	pt[1] = 3;
	
	network_1 = ft_create_petri_net(pt,m0,m_int,m_out);
	if(!network_1)
		return(1);
	assert(network_1->M0 && network_1->M_in && network_1->M_out && network_1->Mp && network_1->Mt && network_1->p && network_1->t);
	
	ft_print_petri_matrice(network_1->M_in,4,3,1);
	ft_print_petri_matrice(network_1->M_out,4,3,1);
	ft_print_network(network_1);
	ft_destroy_network(&network_1);
}
