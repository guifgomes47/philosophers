int	ft_isspace(int n)
{
	if ((n == '\n') || (n == '\t') || (n == '\r') || (n == '\v') || (n == '\f')
		|| (n == ' '))
	{
		return (1);
	}
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sin;
	int	res;

	i = 0;
	sin = 1;
	res = 0;
	while (ft_isspace(nptr[i]))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			sin *= -1;
		}
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		res = (res * 10) + (nptr[i++] - '0');
	}
	return (res * sin);
}
