#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_LIMIT 1000000000
#define LINE_LIMIT 10000

int main(int argc, char *argv[]) {

    if (argc == 1) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }
    
    char *line = NULL;
    size_t curlen = 0;

    char *content = malloc(SIZE_LIMIT);
    size_t len = 1;

    for (int i = 1; i < argc; ++i) {
        FILE *fp = fopen(argv[i], "r");
        while (getline(&line, &curlen, fp) != -1) {
            strcat(content, line);
            len += curlen - 1;
        }
        fclose(fp);
    }

    int start = 0;
    for (int j = 0; j < len; ++j) {
        if (j > 0 && content[j-1] != content[j]) {
            // printf("start: %d, j: %d, char: %c\n", start, j, content[start]);
            int curlen = j - start;
            fwrite(&curlen, sizeof(int), 1, stdout);
            fwrite(content + start, sizeof(char), 1, stdout);
            start = j;
        }
    }

    return 0;
}