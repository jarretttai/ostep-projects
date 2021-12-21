#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc == 1) {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    char *cur = malloc(6);

    for (int i = 1; i < argc; ++i) {
        FILE *fp = fopen(argv[i], "r");
        if (fp) {
            while (fread(cur, 5, 1, fp) == 1) {
                int count = (cur[3] << 24) | (cur[2] << 16) | (cur[1] << 8) | (cur[0]);
                for (int j = 0; j < count; ++j) {
                    printf("%c", cur[4]);
                }
            }
        } else {
            exit(1);
        }

        fclose(fp);
    }

    return 0;
}