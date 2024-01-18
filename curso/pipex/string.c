#include "pipex.h"

int	string_compare(char *str1, char *str2)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] == str2[i])
			flag = 1;
		i++;
	}
	return (flag);
}

char	*get_env(char **strs, char *ref)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (string_compare(strs[i], ref) == 1)
			return (strs[i]);
		i++;
	}
	return (0);
}

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
