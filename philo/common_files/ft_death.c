/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:49:37 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/19 19:02:37 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	ft_set_lmeat(t_philo *p)
{
	p -> l_eat = ft_stime(U_S);
}

int	ft_is_alive(t_philo *p)
{
	return ((ft_stime(U_S) - p -> l_eat) / 1000 <= p ->d->t_alive);
}

void	ft_kill_one(t_philo *p)
{
	pthread_mutex_lock(&(p->pr));
	printf("%d %d died\n", ft_moment(p->d->s_t, ft_stime(U_S)), p->id);
	pthread_mutex_unlock(&(p->pr));
	p ->d->dead = 1;
}

void	ft_kill_all(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p ->d->n_philo)
	{
		ft_kill_one(p);
		p = p->prev;
	}
	return ;
}

int	ft_all_dead(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p->d->n_philo)
	{
		if (!ft_is_alive(p))
			return (1);
	}
	return (0);
}
