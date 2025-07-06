/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description: Main file for virtual memory simulator
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

#include <stdlib.h>
#include <stdio.h>
#include "vm_types.h"
#include "page_table.h"
#include "frame_table.h"
#include "memory_manager.h"
#include "storage_manager.h"
#include "replacement_algorithms.h"

// Global variable definitions
FILE *disk;
page_table_entry_t page_table[NUM_PAGES];
frame_table_entry_t frame_table[NUM_FRAMES];
char memory[MEMORY_SIZE];
int replacement_choice;

void print_menu(void) {
    printf(" Enter : \n 1] FIFO \n 2] LRU \n 3] Clock \n");
}

int main(void) {
    // Initialize all components
    init_storage();
    init_page_table();
    init_frame_table();
    
    // Get user's choice for replacement algorithm
    print_menu();
    scanf("%i", &replacement_choice);
    
    // Initialize chosen algorithm
    switch(replacement_choice) {
        case 1:
            fifo_init();
            break;
        case 2:
            lru_init();
            break;
        case 3:
            clock_init();
            break;
        default:
            printf("Invalid choice, defaulting to FIFO\n");
            replacement_choice = 1;
            fifo_init();
            break;
    }
    
    // Main simulation loop
    unsigned short int virtual_address;
    printf("Enter the virtual address (hexadecimal): ");
    
    if(scanf("%hx", &virtual_address) == 1) {
        printf("\nYou entered: 0X%04x\n", virtual_address);
        
        // Process the virtual address
        unsigned int page_number = get_page_number(virtual_address);
        unsigned int offset = get_offset(virtual_address);
        
        printf("Page Number: %u, Offset: %u\n", page_number, offset);
        
        // Check if page is in memory
        int frame_number = check_page_to_frame(page_number);
        if(frame_number == -1) {
            printf("Page fault occurred for page %u\n", page_number);
            allocate(page_number);
            frame_number = check_page_to_frame(page_number);
        }
        
        // Calculate physical address
        unsigned int physical_address = calculate_physical_address(frame_number, offset);
        printf("Physical Address: %u (0x%04x)\n", physical_address, physical_address);
        
        // Print current state
        print_page_table();
        print_memory_stats();
        
    } else {
        printf("Invalid input\n");
    }
    
    cleanup();
    return 0;
}