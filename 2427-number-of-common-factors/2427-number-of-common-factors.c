int commonFactors(int a, int b) {
    int i=1;
    int count=0;
    int j;
    if(a>b)
    {
         j=a;
    }
    else
    {
        j=b;
    }
    while(i<=j)
    {
        if(a%i==0&&b%i==0)
        {
          count++;
         }
         i++;
    }
    return count;
    
}