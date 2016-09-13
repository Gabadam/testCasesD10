/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akebbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 01:04:37 by akebbour          #+#    #+#             */
/*   Updated: 2016/09/13 22:19:51 by akebbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_sort_wordtab(char **tab);

int		wordtab_len(char **tab);

void	swap_word(char **tab, int i);

int is_white_space(unsigned char c)
{
    if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
        || c == '\r' || c == ' ')
        return (1);
    return (0);
}

int count_word(char *str)
{
    int count;
    char *s;

    count = 0;
    s = str;
    while (*str != '\0')
    {
        if (!is_white_space(*str) && (is_white_space(*(str - 1)) || s == str))
            count++;
        str++;
    }
    return (count);
}

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int len;

    len = 1;
    while ((len++ < size) && *src)
        *dest++ = *src++;
    if (size)
        *dest = '\0';
    while (*src++)
        len++;
    return (len - 2);
}

char** ft_split_whitespaces(char *str)
{
    char **ret;
    char **ret_cpy;
    char *s;
    int word_len;

    if ((ret = malloc(sizeof(char *) * (count_word(str) + 1))) == NULL)
        return (NULL);
    ret_cpy = ret;
    while (*str != '\0')
    {
        while (is_white_space(*str))
            str++;
        s = str;
        word_len = 0;
        while (*str != '\0' && !is_white_space(*str))
        {
            str++;
            word_len++;
        }
        if (word_len && (*ret = malloc(sizeof(char) * ++word_len)) != NULL)
            ft_strlcpy(*ret++, s, word_len);
    }
    *ret = NULL;
    return (ret_cpy);
}

#define ANSI_C0L0R_RED     "\x1b[31m"
#define ANSI_C0L0R_GREEN   "\x1b[32m"
#define ANSI_C0L0R_YELLOW  "\x1b[33m"
#define ANSI_C0L0R_BLUE    "\x1b[34m"
#define ANSI_C0L0R_MAGENTA "\x1b[35m"
#define ANSI_C0L0R_CYAN    "\x1b[36m"
#define ANSI_C0L0R_RESET   "\x1b[0m"

void ft_putchar(char c)
{
    write(1, &c, 1);
}


void ft_putstr(char *str)
{
    if (str != NULL)
        while (*str)
            ft_putchar(*str++);
}

void	show_tab(char **tab)
{
	while (*tab != NULL)
	{
		ft_putstr(*tab);
		ft_putchar('\n');
		tab++;
	}
}

int	main(int argc, char **argv)
{
	char **tab;

	if (argc == 2)
	{
		tab = ft_split_whitespaces(*++argv);
		ft_sort_wordtab(tab);
		show_tab(tab);

	}
	return (0);
}
