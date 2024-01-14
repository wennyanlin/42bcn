#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char	*read_input(char *infile_name);
char	*execute_cmd1();
char	**split(char *string, char separator);
int		count_words(char *string, char separator);
char	*get_next_word(char *string, char separator);
char	*string_concat(char *path, char *cmd);
size_t  ft_strlen(char *str);



#endif

