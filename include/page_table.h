/*
 * =====================================================================================
 *
 *       Filename:  page_table.h
 *
 *    Description: Page table management functions
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

#ifndef PAGE_TABLE_H
#define PAGE_TABLE_H

#include "vm_types.h"

// Page table management functions
void init_page_table(void);
int check_page_to_frame(unsigned int page_number);
void update_page_table(int page, int frame);
void invalidate_page_table_entry(int frame);
void print_page_table(void);

// Address translation functions
unsigned int get_page_number(unsigned short int virtual_address);
unsigned int get_offset(unsigned short int virtual_address);
unsigned int calculate_physical_address(unsigned int frame_number, unsigned int offset);

#endif // PAGE_TABLE_H