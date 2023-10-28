#include "../lib/philo.h"



void *monitor(void *data_pointer)
{
	t_philo *philo;
	philo = (t_philo *)data_pointer;
	philo->data->philo_dead = 1;
	return ((void *)0);
}

int thread_init(t_data *data)
{
	int i;
	pthread_t t0;

	i = -1;
	if (data->meals > 0)
		if(pthread_create(&t0, NULL, &monitor, &data->philos[0]))
			return(123);
	return (0);
}

int init_data(t_data *data, char **argv)
{
	data->philo_nums = (int) ft_atoi(argv[1]);
	data->death_time = (u_int64_t) ft_atoi(argv[2]);
	data->eat_time = (	u_int64_t) ft_atoi(argv[3]);
	data->sleep_time = (u_int64_t) ft_atoi(argv[4]);
	data->meals = (int) ft_atoi(argv[5]);
	if (data->philo_nums <= 0 || data->philo_nums > 200 || data->death_time < 0
	|| data->eat_time < 0 || data->sleep_time < 0)
		return(202);
	data->philo_dead = 0;
	data->finished = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	return (0);
}

int alloc(t_data *data)
{
	data->tid = malloc(sizeof(pthread_t) * data->philo_nums);
	if (!data->tid)
		return (10);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_nums);
	if (!data->forks)
		return (11);
	data->philos =  malloc(sizeof(t_philo) * data->philo_nums);
	if (!data->philos)
		return(12);
	return (0);
}

int init(t_data *data, char **argv)
{
	if (init_data(data, argv))
		return(1);
	if (alloc(data))
		return(1);

	return (0);
}
int input_checker(char **argv)
{
	int i;
	int j;

	i = 1;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if(argv[i][j] == ' ')
			{
				j++;
				continue ;
			}
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (5);
			j++;
		}
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 6)
		return (1);
	if (input_checker(argv))
		return (2);
	if (init(&data, argv))
		return(3);

	// if (thread_init(&data))
		// return (4);
	// if (data->philo_nums == 1)
		// return (case_one(&data));
	printf("Hello World From Android\n");
	return (0);
}
