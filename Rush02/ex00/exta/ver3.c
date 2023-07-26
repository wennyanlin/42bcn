/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarol-g <dcarol-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:26:24 by dcarol-g          #+#    #+#             */
/*   Updated: 2023/07/23 23:01:08 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 1024

extern int	ft_strlen(char *s);
extern int	ft_atoi(char *str, unsigned int *input);
extern int	parse_input2(char *str, unsigned int *input);
extern int	runopen(char *str, unsigned int *input);

int	is_direct(unsigned int *input, int len)
{
	if (len == 1)
		return (1);
	else if (len == 2 && *input >= 10 && *input <= 19)
		return (1);
	else if (len == 2 && (*input % 10 == 0))
		return (1);
	else if (*input == 100 || *input == 1000)
		return (1);
	else if (*input == 1000000 || *input == 1000000000)
		return (1);
	else
		return (0);
}

int is_key_valid(char *key) {
    while (*key != ' ' && *key != ':') {
        if (*key < '0' || *key > '9') {
            printf("Key not int");
            return 0;
        }
        key++;
    }
    return 1;
}

int process_key(char *buf, int *i, unsigned int input, int *start) {
    char poss[10];
    int k = 0;
    int cond = 1;

    while ((buf[*i] != ' ' && buf[*i] != ':') && cond == 1) {
        poss[k] = buf[*i];
        k++;
        (*i)++;
    }
    poss[k] = '\0';
    cond = 0;

    if (!is_key_valid(poss)) {
        return 0;
    }

    unsigned int parsed_key = 0;
    for (int j = 0; poss[j] != '\0'; j++) {
        parsed_key = parsed_key * 10 + (poss[j] - '0');
    }

    if (parsed_key == input) {
        *start = *i;
        return 1;
    }

    (*i)++;
    return -1;
}

int find_key_position(char *buf, ssize_t bytr, unsigned int input, int *start) {
    int i = 0;

    while (bytr > 0) {
        while (buf[i] != '\0') {
            while (buf[i] != '\n') {
                int res = process_key(buf, &i, input, start);
                if (res != -1) {
                    return res;
                }
            }
            i++;
        }
        printf("Run Error 1\n");
        return 0;
    }
    return 0;
}
/*
int main() {
    // Ejemplo de uso de la función find_key_position

    char buffer[] = "Key1: Value1\nKey2: Value2\nKey3: Value3\n";
    ssize_t buffer_size = sizeof(buffer) - 1; // No contar el carácter nulo '\0' al final

    unsigned int key_to_find = 2;
    int start_position = 0;

    int result = find_key_position(buffer, buffer_size, key_to_find, &start_position);

    if (result == 1) {
        printf("Key found! Start position: %d\n", start_position);
    } else if (result == 0) {
        printf("Key not found!\n");
    } else {
        printf("Error while searching for the key.\n");
    }

    return 0;
}
*/
