int numberOfSteps(int num) {
    int c=0;
    while(num)
    {
        c++;
        if(num%2)
            num--;
        else num/=2;}
    return c;
}