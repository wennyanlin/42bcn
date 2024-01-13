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

char	*read_input(char *infile_name)
	{
		int		fd;
		char	buffer[100];
		int		bytes_read;

		fd = open(infile_name, O_RDWR);
		if (fd == -1)
			return (1);
		bytes_read = read(fd, buffer , 100);
		buffer[bytes_read] = '\0';
		printf("%s", buffer);
		return (0);
	}

char	*execute_cmd1(char *cmd1)
{
	char	*args[] = {"ls", "-l", 0};


	execve("/bin/ls", args, 0);
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
	read_input(infile);
	execute_cmd1(cmd1);
}
