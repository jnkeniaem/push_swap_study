int	ft_available(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

/*
원본
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s1[i] == s2[i])
			i++;
		else
		{
			return (s1[i] - s2[i]);
			break ;
		}
		if ((s1[i] == '\0') || (s2[i] == '\0'))
		{
			return (s1[i] - s2[i]);
			break ;
		}
	}
}
그치만 좀 더 깔끔하게 만들었어융
맞겠..지?
*/
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
        else
            break;
	}
    return (s1[i] - s2[i]);
}