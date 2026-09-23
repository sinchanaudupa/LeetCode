int lengthOfLongestSubstring(char* s) {
    int freq[128] = {0};
    int left = 0, max = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        freq[(int)s[right]]++;

        while (freq[(int)s[right]] > 1) {
            freq[(int)s[left]]--;
            left++;
        }

        if (right - left + 1 > max)
            max = right - left + 1;
    }

    return max;
}