/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:18:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/19 19:09:07 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"common_files/philo.h"

//void	ft_void(int n, char **v)
//{
//	(void)n;
//	(void)v;
//}

void	ft_died(t_philo *data)
{
	data -> d -> dead = 1;
}

void	ft_join_t(t_philo *p, t_data *d)
{
	t_philo	*tmp;
	int		i;

	tmp = p;
	i = -1;
	while (++i < d->n_philo)
	{
		pthread_join((tmp->philo), NULL);
		tmp = tmp -> prev;
	}
}

t_data	*ft_ini_data(int n, char **v)
{
	t_data			*data;

	data = NULL;
	if (!main_parsing(n, v))
	{
		data = ft_fill_it(n, v);
		data ->s_t = ft_stime(U_S);
	}
	data ->dead = 0;
	data ->s_t = ft_stime(U_S);
	return (data);
}

int	main(int n, char **v)
{
	t_philo			*lst;
	t_data			*shared;
	int				i;

	shared = NULL;
	shared = ft_ini_data(n, v);
	if (!shared)
		return (ft_print("Error !!!"), 1);
	lst = NULL;
	ft_ini_lst(&lst, shared);
	printf("starting at : %d\n", ft_moment(shared->s_t, ft_stime(U_S)));
	if (!lst)
		return (ft_print("Error !!!"), 1);
	i = 0;
	while (i < shared->n_philo)
	{
		if (pthread_create(&(lst ->philo), NULL, ft_begin, lst))
			return (1);
		lst = lst -> prev;
		i++;
	}
	i = 0;
	while (1)
	{
		if (shared->dead)
			break ;
	}
	return (0);
}
