#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    for (int i = 1; i < argc; ++i) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wcat: cannot open file\n");
            return 1;
        }
        char *line = malloc(LINE_MAX + 1);
        while (fgets(line, LINE_MAX + 1, fp) != NULL) {
            printf("%s", line);
        }
        fclose(fp);
    }
    
    
    return 0;
}