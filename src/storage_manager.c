/*
 * =====================================================================================
 *
 *       Filename:  storage_manager.c
 *
 *    Description: Storage management implementation
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
#include <stdlib.h>
#include <time.h>
#include "storage_manager.h"
#include "vm_types.h"

void init_storage(void) {
    // TODO: Initialize storage file
    // Your existing code had this partially implemented
    // Create virtual_storage.bin file and write initial data
}

void cleanup(void) {
    // TODO: Close storage file and cleanup resources
    // Your existing code had this implemented
}

void load_page_from_storage(int frame_num, int page_num) {
    // TODO: Load page from storage into memory frame
    // Your existing code had this partially implemented
    // Use fseek and fread
}

void save_page_to_storage(int frame_num, int page_num) {
    // TODO: Save page from memory frame to storage
    // Your existing code had this implemented
    // Use fseek and fwrite
}

void random_number_init(int pages[]) {
    // TODO: Initialize pages array with random data
    // Your existing code had this implemented
    // Use srand(time(NULL)) and rand()
}