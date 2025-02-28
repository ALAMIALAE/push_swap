/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:45:28 by aben-dri          #+#    #+#             */
/*   Updated: 2025/02/28 14:43:28 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int is_digit(char *str)
{
    int i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    if (i == 0 || (i == 1 && (str[0] == '+' || str[0] == '-')))
        return 0;
    return 1; 
}
int ft_dup( t_stack *a, int o)
{
    while (a)
    {
        if (a->content == o)
            return (0);
        else 
            a = a->next;
    }
    return(1);
}
void stack_add(t_stack **a, t_stack *new)
{
    if (!new)
        return;
    if (!*a)  
    {
        *a = new;
        return;
    }
    t_stack *current = *a;
    while (current->next)
        current = current->next;
    current->next = new;  
}

void free_s(char **res)
{
    int i = 0;
	while (res[i])
	{
		free(res[i]);			
        i++;
	}
	free(res);
}
void free_l(t_stack *a)
{
    t_stack *tmp;
    while(a)
    {
        tmp = a;
        a = a->next;
        free(tmp);
    }
}
void  parse(int ac, char **av, t_stack **a)
{
    char **res;
    int i = 1;
    int k;
    int j = 0;
    t_stack *tmp = NULL;
    while(i < ac)
    {
        res = ft_split(av[i], ' ');
        if (!res || !*res) 
        {
            free_s(res);
            free_l(*a);
            write(2, "Error\n", 6);
            exit(1);
        }
        j = 0;
        while (res[j])
        {
            if(!is_digit(res[j]))
            {
                free_s(res);
                free_l(*a);
                write(2, "Error\n", 6);
                exit(1);
            }
            k = ft_atoi(res[j]);
            if (limit_int(res[j]))
            {
                free_s(res);
                free_l(*a);
                write(2, "Error\n", 6);
                exit(1);
            }
            if (!ft_dup(*a, k))
            {
                free_s(res);
                free_l(*a);
                write(2, "Error\n", 6);
                exit(1);
            }
            tmp = ft_lstnew(k);
            if (!tmp)
            {
                free_s(res);
                free_l(*a);
                write(2, "Error\n", 6);
                exit(1);
            }
            stack_add(a, tmp);
            j++;
        }
        free_s(res);
        i++;
    }
}