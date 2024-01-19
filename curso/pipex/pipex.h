#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_str
{
	char	*value;
	int		continue_from_index;
}	t_str;


void	read_input(char *infile_name);
char	*execute_command(char *cmd1, char **envp);
char	**split(char *string, char separator);
int		count_words(char *string, char separator);
t_str	get_next_word(char *string, char separator, int continue_from);
t_str	parse_string(char *string, char separator, int continue_from);
char	*string_concat(char *path, char *cmd);
size_t  ft_strlen(char *str);
char	*find_path(char *env, char *cmd);
int		redirect_stdin(char *infile, char *cmd1, char *cmd2, char *outfile, char **envp);
char	*get_env(char **strs, char *ref);
int		string_compare(char *str1, char *str2);


#endif

