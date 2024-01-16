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

int	redirect_stdin(char *infile, char *cmd1, char *cmd2)
{
	int		fd;
	int		pipefd[2];
	int		pid;
	// int		stdin_copy;
	// char	buffer[100];
	// int		count_bytes = 0;

	// stdin_copy = dup(STDIN_FILENO);
	fd = open(infile, O_RDONLY);
	if (fd == -1)
	{
		perror("Error open!");
		return (1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("Error dup2");
		close(fd);
		return (1);
	}
	close(fd);
	if (pipe(pipefd) == -1)
	{
		perror("Error pipe");
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error Forking");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{

		close(pipefd[0]);//close the read-end
		dup2(pipefd[1], STDOUT_FILENO);
		execute_cmd1(cmd1);
		close(pipefd[1]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		// pipefd 0 == stdin
		// pipefd 1 == receives output from cmd1
		close(pipefd[1]);
		// count_bytes = read(pipefd[0], buffer, 99);
		// buffer[count_bytes] = '\0';
		dup2(pipefd[0], STDIN_FILENO);//make pipefd(0)/read-end as STDIN
		execute_cmd1(cmd2);
		close(pipefd[0]);
		// printf("Read after execute command: %s\n", buffer);
	}

	return (0);
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
		cmd_path = string_concat(split_paths[i], "/");
		cmd_path = string_concat(cmd_path, cmd);
		if (access(cmd_path, X_OK) == 0)
		{
			return (cmd_path);
		}
		i++;
	}
	return (NULL);
}

// char	*ft_getenv()

//how does pipe behave when file can't access?

void	read_input(char *infile_name)
	{
		int		fd;
		char	buffer[100];
		int		bytes_read;

		fd = open(infile_name, O_RDWR);
		if (fd == -1)
			return ;
		bytes_read = read(fd, buffer , 99);
		buffer[bytes_read] = '\0';
		printf("%s", buffer);
	}

char	*execute_cmd1(char *cmd1)
{
	char	**args;
	char	*path;
	char	*paths;

// TODO: Replace hard-coded paths with PATH environment variable
	paths = "/Users/wen/.nvm/versions/node/v16.19.0/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Users/wen/.nvm/versions/node/v16.19.0/bin";
	args = split(cmd1, ' ');
	path = find_command_path(paths, args[0]);
	execve(path, args, 0);
	return (0);
}

//1. replace hard-coded command with the 'cmd1'
//pass input to cmd1
//execute cmd2
//output the result in the outfile
/**
 * - figure out how to write to stdin for program/process executed by execve
 * - figure out how to pass information between two programs/processes executed by execve
 * - be careful with execve
 * 	 - what happens after you call it? does your code continue after?
 * 		- try putting a println after you call execve to execute cmd1
 * 	 - you will need to learn a bit about processes & child processes etc
 * - how do we know the command is!!!
*/

int	main(int argc, char **argv)
{
	char	*infile;
	// char	*outfile;
	char	*cmd1;
	char	*cmd2;

	if (argc != 5)
		return (0);
	infile = argv[1];
	cmd1 = argv[2];
	cmd2 = argv[3];
	// outfile = argv[4];
	// read_input(infile);
	// execute_cmd1(cmd1);
	redirect_stdin(infile, cmd1, cmd2);

}
