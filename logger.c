#include "logger.h"

FILE* log_init(char *filename) {
    FILE *file = fopen(filename, "w+");
    return file;
}

int logcat(FILE* log_file, char *message, enum log_level level) {
    int flag = 1;
    long int sistem_time;
    struct tm *local_time;
    char time_str[9];
    sistem_time = time(NULL);
    local_time = localtime(&sistem_time);
    strftime(time_str, 9, "%H:%M:%S", local_time);
    if (level == 0) {
        fprintf(log_file, "%s %s %s", "DEBUG", time_str, message);
    } else if (level == 1) {
        fprintf(log_file, "%s %s %s", "TRACE", time_str, message);
    } else if (level == 2) {
        fprintf(log_file, "%s %s %s", "INFO", time_str, message);
    } else if (level == 3) {
        fprintf(log_file, "%s %s %s", "WARNING", time_str, message);
    } else if (level == 4) {
        fprintf(log_file, "%s %s %s", "ERROR", time_str, message);
    } else {
        flag = 0;
    }
    return flag;
}

int log_close(FILE* log_file) {
    fclose(log_file);
    return 0;
}
