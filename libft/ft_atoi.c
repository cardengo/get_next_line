static int		ft_ret(const char *s, unsigned long long int nbr, int sign)
{
	int	i;

	i = 0;
	while ('1' <= s[i] && s[i] <= '9')
		i++;
	if (i > 18)
		return (sign == -1 ? 0 : -1);
	if (nbr > 9223372036854775807)
		return (sign == -1 ? 0 : -1);
	else
		return (sign * nbr);
}

int				ft_atoi(const char *str)
{
	int						i;
	unsigned long long int	nbr;
	int						sign;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || str[i] == 9 || str[i] == 10
			|| str[i] == 11 || str[i] == 12 || str[i] == 13)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (48 <= str[i] && str[i] <= 57)
			nbr = nbr * 10 + (unsigned long long int)(str[i] - 48);
		else
			return (ft_ret(str, nbr, sign));
		i++;
	}
	return (ft_ret(str, nbr, sign));
}
