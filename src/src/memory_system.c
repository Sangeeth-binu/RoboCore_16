#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "cpu_structure.h"

//Memory memory;
void memory_init(){
    for(uint16_t i =0; i < memory.rom_size ; i++){
        memory.rom[i] = 0;
    }
    for(uint8_t i =0; i < memory.ram_size ; i++){
        memory.ram[i] = 0;
    }
}

bool check_rom_bounds(uint32_t address){
    return (address < 1024);
}

bool check_ram_bounds(uint32_t address){
    return (address < 128);
}

void memory_read(uint32_t address, uint8_t *value){
    if(!check_ram_bounds(address)){
        printf("Memory read out of bounds: %u\n", address);
    }

    *value = memory.ram[address];
}