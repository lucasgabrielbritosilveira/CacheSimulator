#include <stdio.h>
#include <stdlib.h>

int CountLines(char* url) {
    FILE *file;
    char info[10];
    int i = 0;
    file = fopen(url, "r");
    if(file == NULL) {
        printf("Erro ao abrir arquivo\n");
    } else {
        while (fscanf(file, "%s", info) != EOF)
            i++;
    }

    return i;

}
void LoadFile(char* url, int* buffer){
    char info[10];
    FILE *file;
    int i = 0;
    file = fopen(url, "r");
    if(file == NULL) {
        printf("Erro ao abrir arquivo\n");
    } else {
        while (fscanf(file, "%s", info) != EOF)
           buffer[i++] = strtoul(info,NULL,16);
    }
    fclose(file);
}