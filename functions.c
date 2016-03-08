/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 18:31:43 by syusof            #+#    #+#             */
/*   Updated: 2016/03/08 18:45:33 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	"ft_printf.h"

void		lst_add1(t_lst **toplist, t_lst *t_lst1)
{

	t_lst		*lstmp;

	lstmp = NULL;
	lstmp = create_lst1((t_lst1)->content);
	if (*toplist == NULL)
	{
		*toplist = lstmp;
	}
	else
	{
		lstmp->next = *toplist;
		*toplist = lstmp;
	}
	//		*t_lst1 = (*t_lst1)->next;
}

void	ft_push1stback(t_lst **lstmp)
{
	t_lst	*lst;

	lst = NULL;
	lst = *lstmp;
	if ((*lstmp)->content)
	{
		while (lst->next)
		{
			lst = lst->next;
		}
		lst->next = create_lst1((*lstmp)->content);
		*lstmp = (*lstmp)->next;
	}
//						ft_putstr("pushback = ");
//						ft_putstr(((t_name*)(lst->next)->content)->name);
//						ft_putstr("\n");
}


t_lst		*create_lst1(void *content)
{
	t_lst	*curlst;

	curlst = NULL;
	if (!(curlst = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	if (content == NULL)
	{
		curlst->content = NULL;
	}
	else
	{
		if (!(curlst->content = malloc(sizeof(content))))
			return (NULL);
		curlst->content = ft_memmove(curlst->content, content, sizeof(content));
	}
	curlst->next = NULL;
	return (curlst);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;
	char	*temp;

	temp = (char*)malloc(sizeof(char) * n);
	s1 = (char*)dest;
	s2 = (char*)src;
	i = 0;
	while (i < n)
	{
		temp[i] = s2[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		s1[i] = temp[i];
		i++;
	}
	return (s1);
}

char	*ft_strnew(size_t size)
{
	char		*str;
	size_t		i;

	if ((str = (char*)malloc(sizeof(char) * size)))
	{
		i = 0;
		while (i <= size)
		{
			str[i] = 0;
			i++;
		}
		return (str);
	}
	return (NULL);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int				i;
	unsigned int	max;
	char			*str;

	if (start > ft_strlen(s) || (start + len) > ft_strlen(s))
		return (0);
	i = 0;
	str = ft_strnew(len + 1);
	max = start + len;
	while (start <= max)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	return (str);
}
