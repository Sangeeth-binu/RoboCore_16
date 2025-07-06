/*
 * =====================================================================================
 *
 *       Filename:  storage_manager.h
 *
 *    Description: Disk storage management functions
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

#ifndef STORAGE_MANAGER_H
#define STORAGE_MANAGER_H

#include "vm_types.h"

// Storage initialization and cleanup
void init_storage(void);
void cleanup(void);

// Page I/O operations
void load_page_from_storage(int frame_num, int page_num);
void save_page_to_storage(int frame_num, int page_num);

// Utility functions
void random_number_init(int pages[]);

#endif // STORAGE_MANAGER_H