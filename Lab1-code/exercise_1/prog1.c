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

    for (int i = 1; i < argc; i++) {
        strcat(result_str, argv[i]);
    }

    printf("%s\n", result_str);
}