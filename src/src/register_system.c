#include <stdio.h>
#include <stdint.h>
#include "cpu_structure.h"

CPUstate_t CPUState ={0};
extern CPUstate_t CPUState;

CPUState.sp = STACK_TOP;

CPUState.pc = 0x0000;

void readRegister (int reg, uint32_t* value){
    *value = CPUState.registers[reg];
}

void writeRegister(int reg, uint32_t* value){
    *value = CPUState.registers[reg];
}

void check_bound_SP(){
    if (CPUState.sp < STACK_BASE || CPUState.sp > STACK_TOP){
        printf("stack over flow / under flow");
    }
}

void get_flag(uint8_t offset){
    return;
}

void get_input(){

}

void give_output(){

}

void printRegisters(){
    printf("\n --------------------- register values --------------------------\n");
    for (uint8_t i; i<16; i++){
        printf("register[ %i ] = %i \n", i, CPUState.registers[i]);
    }
    printf("\n-----------------------------------------------------------------\n");
}

void printSpecialRegisters(){
     printf("\n ---------------- Special register values ----------------------\n");
    
    printf("\n-----------------------------------------------------------------\n");
}

void track( CPUstate_t *before , CPUstate_t *after){
    /*CPUState_t prev_state = CPUState;

executeInstruction();    */

track_register_changes(&prev_state, &CPUState);  // compare
*/
    printf("----------------------------------------------------------------------------------------------------------------");
    for (uint8_t i =0;i<16;i++){

        if(before->registers[i] != after->registers[i]){
            printf("\n registers[ %i ] => before : %x -> after :%x", i, before->registers[i], after->registers[i]);
        }

    }
    printf("----------------------------------------------------------------------------------------------------------------");
    
    //before thois include prevstate structure to store previos cpustate and also then execute nd then store current state and then call trackk to compare that two 
}