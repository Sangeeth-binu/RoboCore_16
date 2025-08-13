#ifndef CPU_STRUCTURE_H
#define CPU_STRUCTURE_H

#define STACK_BASE 0x70
#define STACK_SIZE 16
#define STACK_TOP 0x7F
#include <stdint.h>
#include <stdbool.h>
void _reset();
void _loadprogram();
void _step();
void _run();

typedef struct _CPUstate {
    uint32_t registers[16];
    uint32_t pc;
    uint32_t sp;
    uint32_t flags;
    uint32_t in_reg;
    uint32_t out_reg;
}CPUstate_t;
extern CPUstate_t CPUState; 



typedef struct _Memory {
    uint8_t rom[1024];
    uint8_t ram[128];
    const uint32_t rom_size;    // RAM Memory Map (128 bytes total)
                                // 0x00-0x6F:  General RAM (112 bytes) - variables, heap, etc.
                                // 0x70-0x7F:  Stack Space (16 bytes) - dedicated stack region
    const uint32_t ram_size;
} Memory;
extern Memory memory;


typedef struct Instruction {
    uint32_t opcode;
    uint32_t rs1, rs2, rd;
    uint32_t immediate;
    uint32_t address;
}Instruction_t;
extern Instruction_t instruction;


typedef struct {
  //  CPUstate_t cpu;
  //  Memory memory;
    bool running;
    void (*__reset)();
    void (* load)();
    void (* run)();
    void (* step)();
} task;




#endif