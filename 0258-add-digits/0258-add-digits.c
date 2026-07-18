int sumdigits(int n)
{
    if (n == 0)
        return 0;

    return (n % 10) + sumdigits(n / 10);
}
int addDigits(int num)
{
    while (num >= 10)
    {
       num= sumdigits(num);
    }

    return num;
}