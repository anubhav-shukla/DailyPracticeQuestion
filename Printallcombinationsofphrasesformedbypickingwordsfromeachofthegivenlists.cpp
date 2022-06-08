#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
// Function to print all combinations of phrases that can be formed
// by words from each of the given lists
void printAllCombinations(vector<vector<string>> const &lists, string result, int n)
{
    // base case
    if (lists.size() == 0) {
        return;
    }
 
    // if we have traversed each list
    if (n == lists.size())
    {
        // print phrase after removing trailing space
        cout << result.substr(1) << endl;
        return;
    }
 
    // get the size of the current list
    int m = lists[n].size();
 
    // do for each word in the current list
    for (int i = 0; i < m; i++)
    {
        // append current word to output
        string out = result + " " + lists[n].at(i);
 
        // recur for the next list
        printAllCombinations(lists, out, n + 1);
    }
}
 
int main()
{
    vector<vector<string>> lists =
    {
        { "John", "Emma" },
        { "Plays", "Hates", "Watches" },
        { "Cricket", "Soccer", "Chess" }
    };
 
    printAllCombinations(lists, "", 0);
 
    return 0;
}
