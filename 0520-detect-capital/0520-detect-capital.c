bool detectCapitalUse(char* word) {
    int capital = 0;

    for (int i = 0; i < strlen(word); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            capital++;
        }
    }

    if (capital == strlen(word) || capital == 0) {
        return true;
    } 
    else if (word[0]>='A'&&word[0]<='Z'&&capital==1)
    {
        return true;
    }
    else {
        return false;
    }
}