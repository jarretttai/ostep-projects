#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    
    char *line = malloc(LINE_MAX+1);
    size_t len = LINE_MAX + 1;

    if (argc == 1) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    
    char *target = argv[1];
    
    if (argc == 2) {
        while (fgets(line, LINE_MAX+1, stdin) != NULL) {
            if (strstr(line, target)) {
                printf("%s", line);
            }
        }
    }

    for (int i = 2; i < argc; ++i) {
        FILE* fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wgrep: cannot open file\n");
            exit(1);
        }
        while (getline(&line, &len, fp) != -1) {
            if (strstr(line, target)) {
                printf("%s", line);
            }
        }

        fclose(fp);
    }

    free(line);

    return 0;
}
