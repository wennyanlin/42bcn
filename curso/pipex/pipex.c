//creating a comunication between two file using pipe
	//create a pipe
		//-> 1. read a file
				//go through the content
		//-> 2. execute a command with the content
				//
		//-> 3. the result will be the input to the other command
				//receives the input from
		//-> 4. output the final result
#include "pipex.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

char	*string_concat(char *path, char *cmd)
{
	char 	*result_path;
	size_t	path_len;
	size_t	cmd_len;
	size_t	total_len;
	size_t	i;

	path_len = ft_strlen(path);
	cmd_len = ft_strlen(cmd);
	total_len = path_len + cmd_len;
	result_path = malloc(sizeof(char) * (total_len + 1));
	if (!result_path)
		return (NULL);
	i = 0;
	while (i < path_len)
	{
		result_path[i] = path[i];
		i++;
	}
	cmd_len = 0;
	while (i < total_len)
		result_path[i++] = cmd[cmd_len++];
	result_path[i] = '\0';
	return (result_path);
}

char	*find_command_path(char *command_paths, char *cmd)
{
	char 	**split_paths;
	char	*cmd_path;
	int		i;

	i = 0;
	split_paths = split(command_paths, ':');
	while (split_paths[i])
	{
		cmd_path = string_concat(split_paths[i], cmd);
		if (access(cmd_path, X_OK))
		{
			printf("path: '%s'\n", cmd_path);
			return (split_paths[i]);
		}
		i++;
	}
	return (NULL);
}

// char	*ft_getenv()

//how does pipe behave when file can't access?

char	*read_input(char *infile_name)
	{
		int		fd;
		char	buffer[100];
		int		bytes_read;

		fd = open(infile_name, O_RDWR);
		if (fd == -1)
			return (NULL);
		bytes_read = read(fd, buffer , 100);
		buffer[bytes_read] = '\0';
		printf("%s", buffer);
		return (0);
	}

char	*execute_cmd1(char *cmd1)
{
	char	**args;
	char	*path;
	char	*paths;

// TODO: Replace hard-coded paths with PATH environment variable
	paths = "/Users/wen/.nvm/versions/node/v16.19.0/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Users/wen/.nvm/versions/node/v16.19.0/bin";
	args = split(cmd1, ' ');
	find_command_path(paths, cmd1);
	path = string_concat("/bin/", args[0]);
	execve(path, args, 0);
	return (0);
}

//1. replace hard-coded command with the 'cmd1'
//pass input to cmd1
//execute cmd2
//output the result in the outfile
/**
 *
 * - be careful with the static variable in split
 * - figure out how to write to stdin for program/process executed by execve
 * - figure out how to pass information between two programs/processes executed by execve
 * - be careful with execve
 * 	 - what happens after you call it? does your code continue after?
 * 		- try putting a println after you call execve to execute cmd1
 * 	 - you will need to learn a bit about processes & child processes etc
 * - how do we know the command is!!!
*/

int	main(/*int argc, char **argv*/)
{
	// char	*infile;
	// char	*outfile;
	// char	*cmd1;
	// char	*cmd2;
	char 	*paths = "/Users/wen/.nvm/versions/node/v16.19.0/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Users/wen/.nvm/versions/node/v16.19.0/bin";
	char **result;
	int		i = 0;

	// if (argc != 5)
	// 	return (0);
	// infile = argv[1];
	// cmd1 = argv[2];
	// cmd2 = argv[3];
	// outfile = argv[4];
	// read_input(infile);
	// execute_cmd1(cmd1);
	// execute_cmd1(cmd2);
	result = split(paths, ':');
	while (i < 7)
	{
		printf("%s\n", result[i]);
		i++;
	}
}
