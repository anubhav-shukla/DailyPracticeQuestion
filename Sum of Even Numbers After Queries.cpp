#include <bits/stdc++.h>

using namespace std;
 
// Function to return the sum of even elements
// after updating value at given index

int EvenSum(vector<int>& A, int index, int value)
{

    // Add given value to A[index]

    A[index] = A[index] + value;
 

    // To store the sum of even elements

    int sum = 0;
 

    for (int i = 0; i < A.size(); i++)
 

        // If current element is even

        if (A[i] % 2 == 0)

            sum = sum + A[i];
 

    return sum;
}
 
// Function to print the result for every query

void BalanceArray(vector<int>& A, vector<vector<int> >& Q)
{
 

    // Resultant vector that stores

    // the result for every query

    vector<int> ANS;
 

    int i, sum;
 

    for (i = 0; i < Q.size(); i++) {
 

        int index = Q[i][0];

        int value = Q[i][1];
 

        // Get sum of even elements after updating

        // value at given index

        sum = EvenSum(A, index, value);
 

        // Store sum for each query

        ANS.push_back(sum);

    }
 

    // Print the result for every query

    for (i = 0; i < ANS.size(); i++)

        cout << ANS[i] << " ";
}
 
// Driver code

int main()
{

    vector<int> A = { 1, 2, 3, 4 };

    vector<vector<int> > Q = { { 0, 1 },

                               { 1, -3 },

                               { 0, -4 },

                               { 3, 2 } };

    BalanceArray(A, Q);
 

    return 0;
}