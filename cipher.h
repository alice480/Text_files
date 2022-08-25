#ifndef SRC_CIPHER_H_
#define SRC_CIPHER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "logger.h"

int menu();
int reading(FILE *file);
int empty_check(char *name);
void caesar_encryption();
void clearing_files();

#endif  // SRC_CIPHER_H_
