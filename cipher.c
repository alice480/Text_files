#include "cipher.h"

int main() {
    menu();
}

int reading(FILE *file) {
    char str[256];
    int flag = 0;
    while (fgets(str, 256, file) != NULL) {
        printf("%s", str);
        flag = 1;
    }
    fclose(file);
    return flag;
}

int empty_check(char *name) {
    int flag = 0;
    FILE *file = fopen(name, "r");
    fseek(file, 0, SEEK_END);
    long pos = ftell(file);
    if (pos > 0)
        flag = 1;
    return flag;
}

int menu() {
    int item, flag = 0;
    int length = 1;
    FILE *file = NULL;
    char *open_file = "";
    #ifdef Quest5
        enum log_level inf = info, err = error;
        FILE *log_file = log_init("log_file2");
    #endif
    while (scanf("%d", &item) && item != -1) {
        flag = 1;
        char *file_name = malloc(sizeof(char));
        if (item == 1) {
            getchar();
            char sim = getchar();
            int index = 0;
            while (sim != '\n') {
                file_name = realloc(file_name, length + 1);
                length++;
                file_name[index] = sim;
                index++;
                sim = getchar();
            }
            file = fopen(file_name, "r");
            open_file = file_name;
            if (file) {
                if (!reading(file))
                    printf("n/a");
                fclose(file);
            } else {
                printf("n/a");
            }
            #ifdef Quest5
                logcat(log_file, strcat(file_name, " open"), inf);
            #endif
            printf("\n");
        } else if (item == 2) {
            getchar();
            char sim = getchar();
            int index = 0;
            int str_length = 0;
            char *new_str = malloc(sizeof(char));
            while (sim != '\n') {
                new_str = realloc(new_str, str_length + 1);
                str_length++;
                new_str[index] = sim;
                index++;
                sim = getchar();
            }
            if (strcmp(open_file, "")) {
                #ifdef Quest5
                    logcat(log_file, strcat(open_file, " item2_segmentation_faul"), err);
                #endif
                if (empty_check(open_file))
                    file = fopen(open_file, "a");
                else
                    file = fopen(open_file, "w");
                if (file) {
                    fprintf(file, "%s", new_str);
                    fclose(file);
                } else {
                    printf("n/a\n");
                }
            } else {
                printf("n/a\n");
            }
        }
        free(file_name);
    }
    if (!flag) {
        printf("n/a");
    }
    #ifdef Quest5
        log_close(log_file);
    #endif
    return 0;
}

