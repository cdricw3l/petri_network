/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptri_network.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:46:05 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/23 21:55:59 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PETRI_NETWORK_H 
#define PETRI_NETWORK_H

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
#include "../utils/string_to_matrice/str_to_matrice.h"

#define PPTR(msg) printf("\x1b[31m" "DEBBUG  de pointeur: >>> "  "%p\n" "\x1b[0m", msg);
#define DEBUGG printf("DEBUGG\n");
#define TEST_START printf("Initiating function test: %s\n", __func__);
#define TEST_SUCCES printf("Function: %s executed successfully.\n", __func__);
#define p_to_t 0
#define t_to_p 1


typedef struct s_petri_network
{
    int     p;              //n place
    int     t;              //n transition
    int     *Mp;            //arr p or actual state
    int     *Mt;            //arr t
    int     *M0;            //initial state
    int     **M_in;         // output tocken W+  post
    int     **M_out;        // intput tocken W-  pre
    int     n;

} t_petri_network;


/* typedef struct s_points
{
    int x;
    int y;
    
} t_points;

typedef struct s_arc
{
    int p;
    int t;
    int weight;
    int direction;
    
} t_arc; */

typedef int* M0;


int                 **ft_create_matrice(int p, int t, int n);
void	            *ft_memset(void *b, int c, size_t len);
void	            ft_print_arr_int(int *arr, int len);
int                 *ft_create_state(int P, int *M_0);

t_petri_network     *ft_create_petri_net(int pt[3], char *m0, char *m_in, char *m_out);
void                ft_print_petri_matrice(int **m, int p, int t, int mode);
void                ft_print_petri_arr(int *arr, int len, int mode);
void                ft_print_network(t_petri_network *network);
int                 ft_network_check(t_petri_network *network, int p);
int                 *ft_create_arr_int(int n);

//memory
void                *ft_destroy_network(t_petri_network **network);
void                *ft_destroy_matrice(int ***matrice, int p);

int                 **ft_get_reachability_matrix(t_petri_network *network);
void                 *ft_clean_reachability_matrix(int ***memory, int idx);
t_petri_network     *ft_extend_network(t_petri_network *network, int n);
int                 **ft_extend_matrice(int ***old_matrice,int x, int y, int n);

//tansition
int                 ft_is_activable_transition(t_petri_network *network, int t, int id);
int                 ft_active_transition(t_petri_network *network, int t, int id);

// tempo
int                 ft_temporisation(int ms, int id, int mode);
int                 get_current_time(void);
float               time_diff(struct timeval *start, struct timeval *end) ;

#endif