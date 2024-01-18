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
char	*execute_cmd1();
char	**split(char *string, char separator);
int		count_words(char *string, char separator);
t_str	get_next_word(char *string, char separator, int continue_from);
char	*string_concat(char *path, char *cmd);
size_t  ft_strlen(char *str);
char	*find_command_path(char *command_paths, char *cmd);
int		redirect_stdin(char *infile, char *cmd1, char *cmd2, char *outfile);



#endif

