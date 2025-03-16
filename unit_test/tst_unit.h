/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_unit.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:23:04 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/16 15:17:12 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TST_UNIT_H
#define TST_UNIT_H

#include "../network/ptri_network.h"
#include "../utils/utils/utils.h"
#include "../utils/ft_split/ft_split.h"

#include <assert.h>
 #include <string.h>

#define DEBUGG printf("DEBUGG\n");
#define PRINT_INT(msg) printf("\x1b[31m" "DEBBUG  INT " "%d\n", msg);
#define PSTR(msg) printf("\x1b[31m" "DEBBUG  str >>> " "%s\n", msg);
#define PPTR(msg) printf("\x1b[31m" "DEBBUG  de pointeur: >>> "  "%p\n" "\x1b[0m", msg);
#define DEBUGG printf("DEBUGG\n");
#define TEST_START printf("Initiating function test: %s\n", __func__);
#define TEST_SUCCES printf("Function: %s executed successfully.\n", __func__);


#define P 4
#define T 3

int test_unit_ft_create_petri_net(void);
int tst_ft_init_arr_arg(void);
int tst_utils(void);
int tst_ft_create_petri_net(void);
int tst_thread_managment(void);

#endif