char** fizzBuzz(int n, int* returnSize) {
    
    char** result = malloc(n * sizeof(char*));
    
    int i = 1;
    
    while(i <= n)
    {
        if(i % 3 == 0 && i % 5 == 0)
        {
            result[i - 1] = "FizzBuzz";
        }
        else if(i % 3 == 0)
        {
            result[i - 1] = "Fizz";
        }
        else if(i % 5 == 0)
        {
            result[i - 1] = "Buzz";
        }
        else
        {
           result[i - 1] = malloc(12 * sizeof(char));
            sprintf(result[i - 1], "%d", i);
        }
        
        i++;
    }
    
    *returnSize = n;
    return result;
}