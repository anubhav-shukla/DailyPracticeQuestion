class Solution {
private: 
    // Helper function to print the frequency array for debugging
    void print(vector<int> v){
        for(auto i:v){
            cout << i << " ";
        }
        cout << "\n";
    }

public:
    bool checkInclusion(string s1, string s2) {
        // Edge case: if s2 is smaller than s1, no permutation is possible
        if(s2.size() < s1.size()) return false;

        int n = s1.size();
        int m = s2.size();

        // Frequency arrays for s1 and the first window of s2
        vector<int> freqS1(26, 0);
        vector<int> freqS2Sub(26, 0);

        // Initialize the frequency arrays for s1 and the first window of s2
        for(int i = 0; i < n; i++) {
            freqS1[s1[i] - 'a']++;
            freqS2Sub[s2[i] - 'a']++;
        }

        // If the first window matches, return true
        if(freqS1 == freqS2Sub) return true;

        // Sliding window across s2
        for(int i = 0; i < m - n; i++) {
            // Update the sliding window
            freqS2Sub[s2[i] - 'a']--;         // Remove the outgoing character
            freqS2Sub[s2[i + n] - 'a']++;     // Add the incoming character

            // Check if the updated window matches the frequency of s1
            if(freqS1 == freqS2Sub) return true;
        }

        // If no match found, return false
        return false;
    }
};