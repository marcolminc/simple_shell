#ifndef TSH_H
#define TSH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define TOKEN_DELIMITER " \t\r\n"
#define MAX_PATH_LENGTH 1024

extern char **environ;

char **tokenize_line(char *line);
void free_tokens(char **tokens);
char *find_executable(char *command);
void execute_tokens(char **tokens);
void read_line(FILE *file);


#endif
