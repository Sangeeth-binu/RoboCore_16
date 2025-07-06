/*
 * =====================================================================================
 *
 *       Filename:  memory_manager.h
 *
 *    Description: Memory management and allocation functions
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

#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include "vm_types.h"

// Memory allocation functions
void allocate(int page_number);
void page_fault(void);
int find_victim_frame(void);

// Memory access functions
int access_memory(unsigned short int virtual_address);
void update_access_time(int frame_number);

#endif // MEMORY_MANAGER_H