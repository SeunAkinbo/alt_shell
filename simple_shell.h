#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL


#include <errno.h>
#include <dirent.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*constants*/
#define INVD_CMD -1
#define INT_CMD 2
#define EXT_CMD 1
#define PTH_CMD 3

#define minimum_Value(a, b) (((a) < (b)) ? (a) : (b))

/**
 *struct mapping_function - a struct that maps command name to a function
 *
 *@cmd_name: name of the command
 *@func: the function that executes the command
 */

typedef struct mapping_function
{
	char *cmd_name;
	void (*func)(char **cmd);
} mapping_to_function;

extern char **environ;

/* Store the user input */
extern char *user_input;
extern char **my_cmds;

/* Store the name of the program*/
extern char *program_name;
extern int status;

int shell_isatty(int fd);

/* help_0- printing, tokenizing & removing newline characters */
void shell_printer(char *sstring, int output_stream);
char **str_tokenizer(char *input_str, char *_delimita);
void newline_remover(char *str);
int _stringlen(char *sstring);
void _strcopy(char *source, char *dest);

/* help_2 */
int _str_comp(char *first, char *second);
char *_str_concat(char *destination, char *source);
int _str_spn(char *str1, char *str2);
int _strcspn(char *str1, char *str2);
char *_strchr(char *s, char c);

/* help_3 */
char *_strtok_r(char *sstring, char *_delimita, char **save_ptr);
int __atoi(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void ctrl_c_handler(int signum);
void remove_comment(char *input);

/* utilities */
int parse_command(char *cmd);
void execute_command(char **cmd_tkn, int cmd_type);
char *chk_path(char *cmd);
void (*get_cmd_function(char *))(char **);
char *_getenv(char *name);

/* implementing the built_in function */
void current_env(char **cmd_tkn __attribute__((unused)));
void exiting_program(char **cmd_tkn);

/* main */
extern void uninteractive(void);
extern void setup_init(char **current_cmd, int cmd_type);
ssize_t _getline(char **line, size_t *len, FILE *stream);
size_t _strlen(const char *str);
char *_fgets(char *buffer, int max_length, FILE *stream);

#endif /* SIMPLE_SHELL */
