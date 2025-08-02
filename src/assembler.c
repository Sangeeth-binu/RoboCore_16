#include <stdio.h>
#include <stdint.h>

FILE *assembly_ptr;

uint32_t ROM[1024];//1kb rom

int cpu_assemble(){
   
    assembly_ptr = fopen("assembly_programs.txt", "r");

    if (assembly_ptr == NULL){
        printf("[error] opening file");
        return 1;
    }

    char BUFFER[32];
    char opcode[3];
    uint8_t count = 0, end = 256;

    while(count != end){
        fgets(BUFFER, sizeof(BUFFER), assembly_ptr);

        opcode[0]=BUFFER[0];
        opcode[1]=BUFFER[1];
        opcode[2]=BUFFER[2];

        
    }



    fclose(assembly_ptr);
}
