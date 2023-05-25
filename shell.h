#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for the buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* this does command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* this is used for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - for singly linked list
 * @num: number field
 * @str: string
 * @next: points to next node in function
 */

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - has pseudo-arguments to pass into function
 * which allows uniform prototype for function pointer struct
 * @arg: string gotten from getline containing arguments
 * @argv: array of strings gotten from arg
 * @path: string path for current command
 * @argc: argument count
 * @line_count:  error count
 * @err_num: error code for exit()s
 * @linecount_flag: count this line of input
 * @fname: program filename
 * @env: linked list local copy of environ
 * @environ: modified copy of environ from linked list env
 * @hist: history node
 * @alias: alias node
 * @env_changed: if environ was changed
 * @status: return status of last executed command
 * @cmd_buf: address of pointer to cmd_buf
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: fd from which to read line input
 * @histcount: history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);
void _puts(char *);
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);
int loophsh(char **);
int stputchar(char c);
int putfd(char c, int fd);
int putsfd(char *str, int fd);
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
int _putchar(char);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
char **strtow(char *, char *);
char **strtow2(char *, char);
int str_conv(char *s);
char *_memset(char *, char, unsigned int);
void ffree(char **);
int _mycd(info_t *info);
int _myhelp(info_t *info);
void *_realloc(void *, unsigned int, unsigned int);
int bfree(void **);
int inter(info_t *info);
int _isalpha(int);
int _myexit(info_t *info);
int str_int(char *s);
int for_delim(char c, char *delim);
void print_error(info_t *, char *);
int print_d(int, int);
char *con_number(long int num, int base, int flags);
void rem_comments(char *buf);
int _myhistory(info_t *);
int _myalias(info_t *);
int myunset_env(info_t *info);
ssize_t get_input(info_t *);
int _myenv(info_t *info);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);
char *get_env(info_t *info, const char *name);
int myset_env(info_t *info);
int fill_env_list(info_t *info);
char **get_environ(info_t *);
int unset_env(info_t *info, char *var);
int set_env(info_t *info, char *var, char *value);
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);
int un_setalias(info_t *info, char *str);
int _setalias(info_t *info, char *str);

#endif /* _SHELL_H_ header */
