/*
 * =====================================================================================
 *
 *       Filename:  page_table.c
 *
 *    Description: Page table management implementation
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

#include <stdio.h>
#include "page_table.h"
#include "vm_types.h"

void init_page_table(void) {
    // TODO: Initialize page table entries
    // Your existing code had this partially implemented
}

int check_page_to_frame(unsigned int page_number) {
    // TODO: Check if page is mapped to a frame
    // Return frame number if mapped, -1 if not
    // Your existing code had this implemented
}

void update_page_table(int page, int frame) {
    // TODO: Update page table entry to map page to frame
}

void invalidate_page_table_entry(int frame) {
    // TODO: Invalidate page table entry for given frame
}

void print_page_table(void) {
    // TODO: Print current page table state
    printf("=== Page Table ===\n");
    printf("Page | Frame | Valid\n");
    printf("-----|-------|------\n");
    // Add your implementation
}

unsigned int get_page_number(unsigned short int virtual_address) {
    // TODO: Extract page number from virtual address
    // Your existing code had: (virtual_address>>12)&(0xf)
    return 0; // Placeholder
}

unsigned int get_offset(unsigned short int virtual_address) {
    // TODO: Extract offset from virtual address
    // Your existing code had: (virtual_address>>4)&(0xfff)
    return 0; // Placeholder
}

unsigned int calculate_physical_address(unsigned int frame_number, unsigned int offset) {
    // TODO: Calculate physical address from frame number and offset
    // Your existing code had: (frame_number * frame_size) + offset
    return 0; // Placeholder
}