 bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for (auto& c : word1) {
            freq1[c-'a']++;
        }
        for (auto& c : word2) {
            if (freq1[c-'a'] == 0) {
                return false;
            }
            freq2[c-'a']++;
        }
        sort(begin(freq1), end(freq1));
        sort(begin(freq2), end(freq2));
        return freq1 == freq2;
    }