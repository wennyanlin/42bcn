#include "pipex.h"

int	redirect_stdin(char *infile, char *cmd1, char *cmd2, char *outfile, char **envp)
{
	int		fd;
	int		fd2;
	int		pipefd[2];
	int		pid;

	fd = open(infile, O_RDONLY);
	fd2 = open(outfile, O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
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
		execute_command(cmd1, envp);
		close(pipefd[1]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(pipefd[1]);
		dup2(fd2, STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);//make pipefd(0)/read-end as STDIN

		execute_command(cmd2, envp);
		close(pipefd[0]);
	}
	return (0);
}

char	*find_path(char *env, char *cmd)
{
	char 	**split_env;
	char 	**all_paths;
	char	*path;
	int		i;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	split_env = split(env, '=');
	all_paths = split(split_env[1], ':');
	while (all_paths[i])
	{
		path = string_concat(all_paths[i], "/");
		path = string_concat(path, cmd);
		if (access(path, X_OK) == 0)
		{
			return (path);
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
	}

char	*execute_command(char *cmd1, char **envp)
{
	char	**args;
	char	*env;
	char	*command_path;

	env = get_env(envp, "PATH");
	args = split(cmd1, ' ');
	command_path = find_path(env, args[0]);
	execve(command_path, args, 0);
	return (0);
}

int	main(int argc, char **argv, char **envp)
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
	redirect_stdin(infile, cmd1, cmd2, outfile, envp);
}
