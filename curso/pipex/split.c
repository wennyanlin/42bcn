#include "pipex.h"

int	count_words(char *string, char separator)
{
	int	count_word;
	int	i;

	i = 0;
	count_word = 0;
	while (string[i])
	{
		while (string[i] && string[i] == separator)
			i++;
		if (string[i] && string[i] != separator)
			count_word++;
		while (string[i] && string[i] != separator)
			i++;
	}
	return (count_word);
}

t_str	get_next_word(char *string, char separator, int	continue_from)
{
	int		i;
	int		j;
	int		len;
	int		end;
	t_str	next_word;

	len = 0;
	i = continue_from;
	j = 0;
	next_word.value = NULL;
	while (string[i])
	{
		while (string[i] && string[i] == separator)
			i++;
		while (string[i + len] && string[i + len] != separator)
			len++;
		next_word.value = malloc(sizeof(char) * (len + 1));
		if (!next_word.value)
			return (next_word);
		end = len + i;
		while (i < end)
			next_word.value[j++] = string[i++];
		next_word.continue_from_index = i;
		next_word.value[j] = '\0';
		return (next_word);
	}
	return (next_word);
}

char	**split(char *string, char separator)
{
	char	**result_array;
	int		num_words;
	int		i;
	t_str	word;

	i = 0;
	word.continue_from_index = 0;
	if (!*string)
		return (NULL);
	num_words = count_words(string, separator);
	result_array = malloc(sizeof(char*) * (num_words + 1));
	if (!result_array)
		return (NULL);
	while (i < num_words)
	{
		result_array[i] = malloc(sizeof(char));
		if (!result_array[i])
			return (NULL);
		word = get_next_word(string, separator, word.continue_from_index);
		result_array[i++] = word.value;
	}
	result_array[i] = NULL;
	return (result_array);
}

// int	main(int argc, char **argv)
// {
// 	int i = 0;
// 	char **result = split(argv[1], ' ');

// 	while (i < 4)
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// }
