#ifndef _SHELL_H_
#define _SHELL_H_
#define UNUSED(x) (void)(x)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
#include <fcntl.h>

int digit(int c);
int _strcmp(char *str1, char *str2);
void simple_error(void);
void print_error(char *argv, int cnt, char *cmd);
void execute_error(char *argv, int cnt, char *temp_cmd);
void print_str(char *str, int newline);


#endif /* _SHELL_H_ header */
