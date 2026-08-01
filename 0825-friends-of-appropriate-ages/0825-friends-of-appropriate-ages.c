int numFriendRequests(int* ages, int agesSize) {
    int freq[121] = {0};
    int count = 0;
    for (int i = 0; i < agesSize; i++) {
        freq[ages[i]]++;
    }
    for (int x = 1; x <= 120; x++) {
        if (freq[x] == 0) {
            continue;
        }
        for (int y = 1; y <= 120; y++) {

            if (freq[y] == 0) {
                continue;
            }
            if (y <= 0.5 * x + 7) {
                continue;
            }

            if (y > x) {
                continue;
            }

            if (y > 100 && x < 100) {
                continue;
            }
            count += freq[x] * freq[y];
            if (x == y) {
                count -= freq[x];
            }
        }
    }

    return count;
}