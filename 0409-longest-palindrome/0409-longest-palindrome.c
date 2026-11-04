
int longestPalindrome(char* s) {
    int freq[128] = {0};
    int count = 0;

    for(int i = 0; s[i] != '\0'; i++)
        freq[s[i]]++;

    for(int i = 0; i < 128; i++) {
        count += (freq[i] / 2) * 2;
    }

    if(count < strlen(s))
        count++;

    return count;
}
