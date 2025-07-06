/*
 * =====================================================================================
 *
 *       Filename:  frame_table.h
 *
 *    Description: Frame table management functions
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

#ifndef FRAME_TABLE_H
#define FRAME_TABLE_H

#include "vm_types.h"

// Frame table management functions
void init_frame_table(void);
int check_for_empty_frame(void);
int get_free_frame_count(void);
void allocate_frame(int frame_number, int page_number);
void deallocate_frame(int frame_number);

// Memory statistics
void print_memory_stats(void);

#endif // FRAME_TABLE_H