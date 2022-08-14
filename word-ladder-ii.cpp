#include <bits/stdc++.h>
using namespace std;
 
// Structure for queue
struct node {
    string word;
    int len;
};
 
// Function that returns true if a and b
// differ in only a single character
bool isAdj(string a, string b)
{
    int count = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i])
            count++;
    }
    if (count == 1)
        return true;
    return false;
}
 
// Function to return the length of the shortest
// chain from ‘beginWord’ to ‘endWord’
int ladderLength(string beginWord, string endWord,
                 vector<string>& wordList)
{
 
    /* q1 is used to traverse the graph from beginWord
        and q2 is used to traverse the graph from endWord.
        vis1 and vis2 are used to keep track of the
        visited states from respective directions */
    queue<node> q1;
    queue<node> q2;
    unordered_map<string, int> vis1;
    unordered_map<string, int> vis2;
 
    node start = { beginWord, 1 };
    node end = { endWord, 1 };
 
    vis1[beginWord] = 1;
    q1.push(start);
    vis2[endWord] = 1;
    q2.push(end);
 
    while (!q1.empty() && !q2.empty()) {
 
        // Fetch the current node
        // from the source queue
        node curr1 = q1.front();
        q1.pop();
 
        // Fetch the current node from
        // the destination queue
        node curr2 = q2.front();
        q2.pop();
 
        // Check all the neighbors of curr1
        for (auto it = wordList.begin(); it != wordList.end(); it++) {
 
            // If any one of them is adjacent to curr1
            // and is not present in vis1
            // then push it in the queue
            if (isAdj(curr1.word, *it) && vis1.count(*it) == false) {
 
                node temp = { *it, curr1.len + 1 };
                q1.push(temp);
                vis1[*it] = curr1.len + 1;
 
                // If temp is the destination node
                // then return the answer
                if (temp.word == endWord) {
                    return temp.len;
                }
 
                // If temp is present in vis2 i.e. distance from
                // temp and the destination is already calculated
                if (vis2.count(temp.word)) {
                    return temp.len + vis2[temp.word] - 1;
                }
            }
        }
 
        // Check all the neighbors of curr2
        for (auto it = wordList.begin(); it != wordList.end(); it++) {
 
            // If any one of them is adjacent to curr2
            // and is not present in vis1 then push it in the queue.
            if (isAdj(curr2.word, *it) && vis2.count(*it) == false) {
 
                node temp = { *it, curr2.len + 1 };
                q2.push(temp);
                vis2[*it] = curr2.len + 1;
 
                // If temp is the destination node
                // then return the answer
                if (temp.word == beginWord) {
                    return temp.len;
                }
 
                // If temp is present in vis1 i.e. distance from
                // temp and the source is already calculated
                if (vis1.count(temp.word)) {
                    return temp.len + vis1[temp.word] - 1;
                }
            }
        }
    }
    return 0;
}
 
// Driver code
int main()
{
 
    vector<string> wordList;
    wordList.push_back("poon");
    wordList.push_back("plee");
    wordList.push_back("same");
    wordList.push_back("poie");
    wordList.push_back("plie");
    wordList.push_back("poin");
    wordList.push_back("plea");
 
    string start = "toon";
    string target = "plea";
 
    cout << ladderLength(start, target, wordList);
 
    return 0;
}