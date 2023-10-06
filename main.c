#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h>     // for sleep()
#include <string.h>

char* longest_common_subsequence(char* x, int x_length, char* y, int y_length) {
    int array[x_length + 1][y_length + 1];

    for (int i = 0; i < x_length + 1; i++) {
        for (int j = 0; j < y_length + 1; j++) {
            array[i][j] = 0; 
        }
    }
    
    for (int i = 1; i < x_length + 1; i++) {
        for (int j = 1; j < y_length + 1; j++) {
            if (x[i-1] == y[j-1]) {
                array[i][j] = array[i-1][j-1] + 1;
            } else {
                if (array[i-1][j] > array[i][j-1]) {
                    array[i][j] = array[i-1][j];
                } else {
                    array[i][j] = array[i][j-1];
                }
            }
            printf("%d", array[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    int substring_length = array[x_length][y_length];
    printf("%d\n", substring_length);
    char* substring = (char *)malloc((substring_length) * sizeof(char));

    int substring_index = substring_length-1;
    int i = x_length;
    int j = y_length;
    while (i > 0 && j > 0) {
        if (array[i][j] == array[i][j-1]) {
            j--;
        } else if (array[i][j] == array[i-1][j]) {
            i--;
        } else {
            printf("%c", y[j-1]);
            substring[substring_index--] = y[j-1];
            i--; 
            j--;
        }
    }
    printf("\n");
    return substring;
}

char* longest_continuous_common_subsequence(char* x, int x_length, char* y, int y_length) {
    int array[x_length + 1][y_length + 1];

    for (int i = 0; i < x_length + 1; i++) {
        for (int j = 0; j < y_length + 1; j++) {
            array[i][j] = 0; 
        }
    }
    
    int max_length = 0;
    int max_i = 0;
    for (int i = 1; i < x_length + 1; i++) {
        for (int j = 1; j < y_length + 1; j++) {
            if (x[i-1] == y[j-1]) {
                array[i][j] = array[i-1][j-1] + 1;
                if (array[i][j] > max_length) {
                    max_length = array[i][j];
                    max_i = i - 1 ;
                }
            } 
            printf("%d", array[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    int substring_length = max_length;
    printf("%d\n", substring_length);
    char* substring = (char *)malloc((substring_length) * sizeof(char));

    printf("%u", max_i);
    for (int i = 0; i < max_length; i++) {
        substring[max_length - 1 - i] = x[max_i - i];
    }
    return substring;
}

int main(char *argc, char* argv[]) {
    // int i;
    // // printf("%d\n",argc);
    // for(i=0;i<*argc-1;i++)
    // {
    //     printf("%s",argv[i]);
    // }
    // char *x = "CACMYCCA";
    // char *y = "MCMAMYCCMAY";

    char x[99];
    char y[99];

    FILE *file;
    char* file_name = argv[1];
    printf("%lu\n", sizeof(file_name)/sizeof(char));
    for (int i = 0; i < sizeof(file_name)/sizeof(char); i++) {
        printf("%c", file_name[i]);
    }
    printf("\n");
    file = fopen(argv[1], "r");

    fscanf(file, "%s", x);
    int x_length = strlen(x);
    printf("%u\n", x_length);
    fscanf(file, "%s", y);
    int y_length = strlen(y);
    printf("%u\n", y_length);

    // fclose(file);

    char* answer = longest_common_subsequence(y, y_length, x, x_length);
    for (int i = 0; i < strlen(answer); i++)
    {
        printf("%c", answer[i]);
    }
    printf("\n");
    
    return 0;
}