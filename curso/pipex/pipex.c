#include "pipex.h"

int	redirect_stdin(char *infile, char *cmd1, char *cmd2, char *outfile)
{
	int		fd;
	int		fd2;
	int		pipefd[2];
	int		pid;

	fd = open(infile, O_RDONLY);
	fd2 = open(outfile, O_RDWR | O_CREAT);
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
		close(pipefd[1]);
		dup2(fd2, STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);//make pipefd(0)/read-end as STDIN

		execute_cmd1(cmd2);
		close(pipefd[0]);
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

int	main(int argc, char **argv)
{
	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd2;

	if (argc != 5)
		return (0);
	infile = argv[1];
	cmd1 = argv[2];
	cmd2 = argv[3];
	outfile = argv[4];
	if (access(outfile, F_OK) != 0)
	{
		open(outfile, O_CREAT | O_WRONLY);
	}
	redirect_stdin(infile, cmd1, cmd2, outfile);
}
