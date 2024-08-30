#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;
void print_prompt(void);
char *read_line(void);
char **split_string(char *buf, char **env);
char **check_path(char *path);
char **find_path(char **env);
int comm_stat(char **input, char **path);
int execute(char **av, int stat, char **env, char **argv);
void print_env(char **environ);
void _free(char **argv);
int _strlen(char *str);
char *_strcpy(char *str1, char *str2);
char *_strcat(char *str1, char *str2);
int _strcmp(char *str1, char *str2);
char *_strdup(char *str);
void sig_handler(int sig);
char *get_env(char *name);
int handle_error(char *argv, char *comm);

#endif
