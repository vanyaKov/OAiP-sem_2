#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // файл чтения
    char * filename = "F1.txt";
    // чтение из файла
    FILE *fp = fopen(filename, "r");
    FILE *fout = fopen("F2.txt", "w");
    
    char buffer[256];
    
        int i;
        int val;
        char *next;
        int count=0;
        
        while (fgets(buffer,256,fp)) {
            if(count%2==0) {
                fprintf(fout, "%s", buffer);
            }
            count++;
        }
            
    fclose(fp);
    fclose(fout);
    return 0;
}