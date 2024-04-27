int	ft_intlen(int n)
{
	int	len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}
