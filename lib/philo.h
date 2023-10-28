#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

struct s_data;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t t1;
	int id;
	int eat_count;
	int status;
	int eating;
	u_int64_t time_to_die;
	pthread_mutex_t lock;
	pthread_mutex_t *r_fork;
	pthread_mutex_t *l_fork;
}	t_philo;

typedef struct s_data
{
	pthread_t *tid;
	int philo_nums;
	int philo_dead;
	int meals;
	int finished;
	u_int64_t death_time;
	u_int64_t eat_time; 
	u_int64_t sleep_time;
	u_int64_t start_time;
	pthread_mutex_t *forks;
	pthread_mutex_t lock;
	pthread_mutex_t write;
	t_philo	*philos;
}	t_data;

//|Utils
int	ft_atoi(const char *nptr);

#endif
