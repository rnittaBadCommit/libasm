/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:29:33 by ncolomer          #+#    #+#             */
/*   Updated: 2022/04/27 16:37:47 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/*
 ** Useful macro
 */
# define ATOI_BASE(s, b)	f |= !!check_atoi(s, b);

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

/*
 ** print a list elements one by line
 */
	void
printf_list(t_list *list)
{
	while (list)
	{
		printf("; %s\n", list->data);
		list = list->next;
	}
}

/*
 ** free a whole list and it's data field
 */
	void
ft_lstclear(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->data)
			free((*list)->data);
		free(*list);
		*list = tmp;
	}
}

/*
 ** Function prototypes
 */
int		ft_atoi_base(char const *str, char const *base);
int		ft_atoi_base_test(char const *str, char const *base);

void	ft_list_push_front(t_list **begin_list, void *data);

int		ft_list_size(t_list *begin_list);

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void*));

void	ft_list_sort(t_list **begin_list,int (*cmp)());

/*
 ** Start !
 */

int	check_atoi(char *s1, char *base)
{
	int	actual;
	int	expected;

	actual = ft_atoi_base(s1, base);
	expected = ft_atoi_base_test(s1, base);
	if (actual == expected)
	{
		printf("OK\n");
		return (0);
	}
	else
	{
		printf("s: %s, base: %s, actual: %d, expected: %d\n", s1, base, actual, expected);
		return (-1);
	}
}

int		main(void)
{
	int	f;

	f = 0;
		ATOI_BASE("", "0123456789")
	printf("\n--ft_atoi_base\n");
	ATOI_BASE("42", "0123456789")
		ATOI_BASE("0", "0123456789")
		ATOI_BASE("", "0123456789")
		ATOI_BASE("1", "0123456789")
		ATOI_BASE("1215415478", "0123456789")
		ATOI_BASE("-0", "0123456789")
		ATOI_BASE("-1", "0123456789")
		ATOI_BASE("-42", "0123456789")
		ATOI_BASE("--42", "0123456789")
		ATOI_BASE("-+-42", "0123456789")
		ATOI_BASE("-+-+-+42", "0123456789")
		ATOI_BASE("-+-+-+-42", "0123456789")
		ATOI_BASE("-1215415478", "0123456789")
		ATOI_BASE("2147483647", "0123456789")
		ATOI_BASE("2147483648", "0123456789")
		ATOI_BASE("-2147483648", "0123456789")
		ATOI_BASE("-2147483649", "0123456789")
		ATOI_BASE("2a", "0123456789abcdef")
		ATOI_BASE("ff", "0123456789abcdef")
		ATOI_BASE("poney", "poney")
		ATOI_BASE("dommage", "invalid")
		ATOI_BASE("dommage", "aussi invalide")
		ATOI_BASE("dommage", "+toujours")
		ATOI_BASE("dommage", "-stop")
		ATOI_BASE("dommage", "  \t\nca suffit")
		ATOI_BASE("dommage", " ")
		ATOI_BASE("dommage", "")
		ATOI_BASE("    +42", "0123456789")
		ATOI_BASE("    -42", "0123456789")
		ATOI_BASE("    42", "0123456789")
		ATOI_BASE("  \t\n\r\v\f  42", "0123456789")
		ATOI_BASE("  \t\n\r\v\f  -42", "0123456789")
		ATOI_BASE("42FINIS !", "0123456789")
		ATOI_BASE("-42FINIS !", "0123456789")
		ATOI_BASE("C'est dommage42", "0123456789")
		printf("-done\n");
		if (!f)
			printf("\n\n================== ALL OK !! ===================\n\n\n");

}
