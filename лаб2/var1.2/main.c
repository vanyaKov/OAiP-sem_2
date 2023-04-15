#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // файл чтения
    char * filename = "input.txt";
    // чтение из файла
    FILE *fp = fopen(filename, "r");
    FILE *fout = fopen("output.txt", "w");
    
    char buffer[256];
    
    fgets(buffer,256,fp);
    
        int i;
        long val;
        char *next;
        int count=0;
        int num;
        
    scanf("%d", &num);
        
        for (i = 0; i < strlen(buffer); i++) {
            val = strtol (&buffer[i], &next, 10);
            printf("%ld ",val);
            
            if (val!=0 && val%num==0) {
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