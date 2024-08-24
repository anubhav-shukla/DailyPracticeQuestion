#define ll long long int

class Solution {
    // Function to generate a palindrome by mirroring the left part
    ll getPalindrome(ll leftPart, bool even) {
        ll res = leftPart;
        if (!even) leftPart /= 10;  // Skip the middle digit if the length is odd
        while (leftPart > 0) {
            res = res * 10 + (leftPart % 10);  // Mirror the digits
            leftPart /= 10;
        }
        return res;
    }

public:
    string nearestPalindromic(string str) {
        ll len = str.length();
        bool even = len % 2 == 0;  // Check if the length of the number is even
        ll midInd = len / 2;
        if (even) midInd -= 1;  // Adjust for even length
        
        ll leftPart = stoll(str.substr(0, midInd + 1));  // Extract the left part of the number
        
        // List of potential palindrome candidates
        vector<ll> possible;
        // Palindrome with current left part
        possible.push_back(getPalindrome(leftPart, even));    
        // Palindrome with incremented left part     
        possible.push_back(getPalindrome(leftPart + 1, even)); 
        // Palindrome with decremented left part     
        possible.push_back(getPalindrome(leftPart - 1, even));   
        // Lower bound edge case (e.g., 999)
        possible.push_back(((ll)pow(10, len - 1)) - 1);
        // Upper bound edge case (e.g., 1001)             
        possible.push_back(((ll)pow(10, len)) + 1);                 
        
        ll ans = 0, diff = LLONG_MAX, num = stoll(str);

        // Find the closest palindrome
        for (auto n : possible) {
            if (n == num) continue;  // Skip the original number itself
            ll curr = abs(num - n);
            if (diff > curr) {
                ans = n;
                diff = curr;
            }
            else if (diff == curr) {
                ans = min(ans, n);  // In case of a tie, choose the smaller palindrome
            }
        }

        return to_string(ans);  // Return the closest palindrome as a string
    }
};