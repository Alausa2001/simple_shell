#ifndef MAIN_H
#define MAIN_H

/** External  Libraries **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int _putchar(char c);
void _puts(char *str);
int _strlen(char *str);
unsigned int nbr_spaces(char *s);
char **_strtok(char *str);
char execute(char **cmd, char **env);

#endif
