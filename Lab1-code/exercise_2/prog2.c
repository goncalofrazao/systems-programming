#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *result_str;
    int result_len;
    
    for (int i = 1; i < argc; i++) {
        result_len += strlen(argv[i]);
    }

    result_str = malloc(result_len * sizeof(char) + 1);
    
    result_len = 0;
    for (int i = 1; i < argc; i++) {
        int len = strlen(argv[i]);
        for (int j = 0; j < len; j++) {
            result_str[result_len++] = argv[i][j];
        }
    }

    printf("%s\n", result_str);
}
