#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char * filename = "fileA.txt";
    FILE *fp = fopen(filename, "r");
    FILE *fout = fopen("fileB.txt", "w");
    
    char buffer[256];
    
    fgets(buffer,256,fp);
    
        int i;
        long val;
        char *next;
        int count=0;
        
        for (i = 0; i < strlen(buffer); i++) {
            val = strtol (&buffer[i], &next, 10);
            
            if (val!=0 && val>0) {
                fprintf(fout, "%ld ", val);
                printf("%c",*next);
                while (val) {
                    val/=10;
                    count++;
                }
            }
            i=next-buffer;
        }
    
    fclose(fp);
    fclose(fout);
    return 0;
}