#include<bits/stdc++.h>

using namespace std;
 
// Utility function to check if a string is a
// palindrome

bool isPalindrome(string str)
{

    int len = str.length();
 

    // compare each character from starting

    // with its corresponding character from last

    for (int i = 0; i < len/2; i++ )

        if (str[i] != str[len-i-1])

            return false;
 

    return true;
}
 
// Function to check if a palindrome pair exists

bool checkPalindromePair(vector <string> vect)
{

    // Consider each pair one by one

    for (int i = 0; i< vect.size()-1; i++)

    {

        for (int j = i+1; j< vect.size() ; j++)

        {

            string check_str;
 

            // concatenate both strings

            check_str = vect[i] + vect[j];
 

            // check if the concatenated string is

            // palindrome

            if (isPalindrome(check_str))

                return true;
 

            // check for other combination of the two strings

            check_str = vect[j] + vect[i];

            if (isPalindrome(check_str))

                return true;

        }

    }

    return false;
}
 
// Driver code

int main()
{

    vector <string> vect = {"geekf", "geeks", "or",

                            "keeg", "abc", "bc"};
 
 

    checkPalindromePair(vect)? cout << "Yes" :

                               cout << "No";

    return 0;
}