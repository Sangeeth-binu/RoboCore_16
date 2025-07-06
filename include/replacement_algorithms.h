/*
 * =====================================================================================
 *
 *       Filename:  replacement_algorithms.h
 *
 *    Description: Page replacement algorithm implementations
 *
 *        Version:  1.0
 *        Created:  15/06/25 12:35:13 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: sangeeth_binu 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef REPLACEMENT_ALGORITHMS_H
#define REPLACEMENT_ALGORITHMS_H

#include "vm_types.h"

// Page replacement algorithms
int fifo_replacement(void);
int lru_replacement(void);
int clock_replacement(void);

// Algorithm-specific helper functions
void fifo_init(void);
void lru_init(void);
void clock_init(void);

// Algorithm state management
void update_replacement_state(int frame_number, int algorithm);

#endif // REPLACEMENT_ALGORITHMS_H