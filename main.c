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
            substring[substring_index--] = y[i-1];
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
                    max_i = i;
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

    for (int i = 0; i <= max_length; i++) {
        substring[i] = x[max_i - i];
        printf("%c", x[max_i - i]);

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
    char *x = "CACMYCCA";
    char *y = "MCMAMYCCMAY";

    // FILE *file;
    // char* file_name = argv[1];
    // printf("%s", file_name);
    // file = fopen(argv[1], "r");

    // fscanf(file, "%s", x);
    int x_length = strlen(x);
    // fscanf(file, "%s", y);
    int y_length = strlen(y);

    // fclose(file);

    longest_continuous_common_subsequence(y, y_length, x, x_length);
    return 0;
}