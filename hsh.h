#ifndef HSH_H
#define HSH_H

/* includes */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

/* Definitions */
#define BUF_SIZE 1024
#define TOKEN_DELIM " \n"

/**
 * struct built_in - a list of built-in commands
 * @name: the name of the built-in command
 * @function: custom built-in function pointer
 */
typedef struct built_in
{
	const char *name;
	int (*function)(void);
} Built_in;

/* externs */
extern char **environ;

/* Functions */
int _putchar(char c);
void hsh(void);
void prompt(void);
char **tokenizer(char *line);
int hsh_exec(char **);
int path_execute(char **args);
void path_append(char **);
int match_built_in(char **args);

int hsh_exit(void);
int hsh_env(void);

#endif
