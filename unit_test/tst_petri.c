/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_petri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:55:10 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/16 14:43:53 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_unit.h"



int tst_ft_create_petri_net(void)
{
	t_petri_network	*network_1;
	TEST_START;
	
	int	pt[2];
	char	*m0 = strdup("1 0 0 1");
	char	*m_out = strdup("1 0 0 0 1 0 0 0 3 0 1 0");
	char	*m_int = strdup("1 0 0 0 1 0 0 0 3 0 1 0");
	
	pt[0] = P;
	pt[1] = T;
	
	network_1 = ft_create_petri_net(pt,m0,m_int,m_out);
	if(!network_1)
		return(1);
	assert(network_1->M0 && network_1->M_in && network_1->M_out && network_1->Mp && network_1->Mt && network_1->p && network_1->t);
	
	ft_print_petri_matrice(network_1->M_in,4,3,1);
	ft_print_petri_matrice(network_1->M_out,4,3,1);
	ft_print_network(network_1);
	
	
	// check_network: check the  pointeurs of the petri structur. I also destroy manully somme array in the structur and destroy the network,
	// for checking the potentially double free. After be freed, all the pointeur point on NULL;
	assert(ft_network_check(network_1,pt[0]));
	free(network_1->M_in[3]);
	network_1->M_in[3] = NULL;
	assert(!ft_network_check(network_1,pt[0]));
	//network_1->M_in[3] = ft_create_arr_int(network_1->t);
	assert(network_1->M_in[3] == NULL);
	assert(!ft_network_check(network_1,pt[0]));
	ft_print_petri_matrice(network_1->M_in,4,3,1);
	
	free(network_1->M_in[1]);
	network_1->M_in[1] = NULL;
	printf("\n\n");
	ft_print_petri_matrice(network_1->M_in,4,3,1);
	//destroye and check memory;
	ft_destroy_network(&network_1);
	assert(!ft_network_check(network_1, P));
	ft_print_network(network_1);

	
	return(1);
	
}




