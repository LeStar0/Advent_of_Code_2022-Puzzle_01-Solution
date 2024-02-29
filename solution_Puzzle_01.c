#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main() {

    int x = 0;
    int y;
    FILE *filePointer_in;
    FILE *filePointer_out;

    filePointer_in = fopen("input_Puzzle_01.txt", "r");
    filePointer_out = fopen("output_Puzzle_01.txt", "w");

    if(filePointer_in == NULL || filePointer_out == NULL) {
        printf("File not found\n");
        exit(1);
    }
    else {
        printf("Found File!\n\n");
    }

    char buffer[100];
    int elfs[256];
    int temp = 0;
    int elf_Count = 0;
    
    while(fgets(buffer, 100, filePointer_in)) {           

        if(isdigit(buffer[0])) {
            temp += atoi(buffer);
             
        }
        else {
            elfs[elf_Count] = temp;
            temp = 0;
            elf_Count++;
            //printf("%d: %d\n", elf_Count, elfs[elf_Count]);
        }    
    }   


    // print all elfs to output file
    for(int i = 0;i <= elf_Count; i++) {
        fprintf(filePointer_out, "%d\n", elfs[i]);
    }

    // Find Max Elfs
    int i_counter;
    int j_counter;
    int max_elf_index[3];
    int max_Val[3];
    int alrdy_there = 0;
    int y_counter = 0;
    
    for(j_counter = 0; j_counter <= 2;j_counter++) {    	

        max_Val[j_counter] = elfs[0];

        for(i_counter = 0; i_counter < elf_Count; i_counter++) {
            
            if((max_Val[j_counter] >= elfs[i_counter]) ) {
                
                continue;
            }               
            else {
                
                switch(j_counter)
                {
                    case 0: 
                        max_Val[j_counter] = elfs[i_counter];
                        max_elf_index[j_counter] = i_counter;
                        break;
                    default:
                        
                        y_counter = j_counter - 1;
                        if(i_counter == max_elf_index[y_counter]) {
                                break;
                        }
                        else {
                            y_counter = j_counter -2;
                            if(i_counter == max_elf_index[y_counter]) {
                                break;
                        }

                            max_Val[j_counter] = elfs[i_counter];
                            max_elf_index[j_counter] = i_counter;
                            break;
                        }

                         
                }   
            }                    
                                 
            
                
        }

    }

    for(int c = 0; c <= 2; c++) {
        printf("Elf Nummer %d hat %d Kalorien \n", max_elf_index[c] + 1, max_Val[c]);
        // die + 1 damit der Index mit der Zeilennummer im output file übereinstimmt
        // die nicht von 0 aus gezählt wird
        
    }
    printf("TOTAL: %d", max_Val[0] + max_Val[1] + max_Val[2]);

    
    

    fclose(filePointer_in);
    fclose(filePointer_out);
    return 0;
}