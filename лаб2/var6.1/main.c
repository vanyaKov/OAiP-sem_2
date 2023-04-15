#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // файл чтения
    char * filename = "f.txt";
    // чтение из файла
    FILE *fp = fopen(filename, "r");
    FILE *fout = fopen("g.txt", "w");
    
    char buffer[256];
    
    fgets(buffer,256,fp);
    
        int i;
        float val;
        char *next;
        int count=0;
        float num;
        int indx=0;
        float min=100;
        int amount=0;
        
        scanf("%f",&num);
        
        for (i = 0; i < strlen(buffer); i++) {
            val = strtof (&buffer[i], &next);
            amount++;
            
            if (val!=0 && (fabsf(val-num)<min)) {
                min=fabsf(val-num);
                indx=amount;
                printf("%c",*next);
                while (val) {
                    val/=10;
                    count++;
                }
            }
            i=next-buffer;
        }
    fprintf(fout,"%d",indx);
    
    fclose(fp);
    fclose(fout);
    return 0;
}