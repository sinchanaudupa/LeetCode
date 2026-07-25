
int maxProduct(int n) {
    int first = 0;
    int second = 0;
    int digit;

    while (n > 0) {
        digit = n % 10;
        n = n / 10;

        if (digit > first) {
            second = first;
            first = digit;
        }
        else if (digit > second) {
            second = digit;
        }
    }

    return first * second;
}

