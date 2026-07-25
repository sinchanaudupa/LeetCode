bool sahi(int have[] ,int need[])
{
    for(int i=0;i<256;i++)
    {
        if(have[i]<need[i])
        {
            return false;
        }
    }
     return true;
}
char* minWindow(char* s, char* t) {
    int n = strlen(s);
    int m = strlen(t);
    int have[256] = {0};
    int need[256] = {0};
    int low = 0;
    int res = INT_MAX;
    int start = -1;

    if(n<m)
    {
        return "";
    }
    
    for(int i=0;i<m;i++)
    {
        need[(unsigned char)t[i]]++;
    }
    for(int high=0;high<n;high++)
    {
         have[(unsigned char)s[high]]++;
         while (sahi(have, need))
        {
            int len = high - low + 1;

            if (res > len)
            {
                res = len;
                start = low;
            }
            have[(unsigned char)s[low]]--;
            low++;
    }
    
}
 if (res == INT_MAX)
    {
        return "";
    }
char* result = (char*)malloc((res + 1) * sizeof(char));
    
strncpy(result, s + start, res);
result[res] = '\0';

return result;
}
