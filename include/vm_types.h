/*
 * =====================================================================================
 *
 *       Filename:  vm_types.h
 *
 *    Description: Type definitions and constants for virtual memory simulator
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

#ifndef VM_TYPES_H
#define VM_TYPES_H

#include <stdint.h>
#include <stdio.h>

// Constants
#define MEMORY_SIZE 65536
#define FRAME_SIZE 4096
#define NUM_PAGES 32
#define NUM_FRAMES 16
#define INVALID_FRAME 17

// Type definitions
typedef struct {
    uint8_t frame_number;
    uint8_t valid;
    uint8_t reference_bit;  // For clock algorithm
    uint32_t timestamp;     // For LRU algorithm
} page_table_entry_t;

typedef struct {
    uint8_t page_number;
    uint8_t occupied;
    uint32_t last_access_time;
} frame_table_entry_t;

// Global variables (extern declarations)
extern FILE *disk;
extern page_table_entry_t page_table[NUM_PAGES];
extern frame_table_entry_t frame_table[NUM_FRAMES];
extern char memory[MEMORY_SIZE];
extern int replacement_choice;

#endif // VM_TYPES_H