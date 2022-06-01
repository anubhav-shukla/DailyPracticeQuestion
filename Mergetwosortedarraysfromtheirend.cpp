#include<iostream>
#include<vector>

using namespace std;

void printArray(vector<int> &arr){
       for(int i : arr){
           cout << i << " ";
       }
       cout << endl;
}

vector <int> merge(vector<int> const &X, vector<int> const &Y){
    int i=X.size()-1, j=Y.size()-1;
    vector<int> aux(X.size() + Y.size());
    int k =0;

    while(i>=0 && j>=0){
        if(X[i]>=Y[j]){
        aux[k++] = X[i--];

    }else{
        aux[k++] = Y[j--];
    }
    }

    while (i>=0)
    {
        aux[k++] = X[i--];
    }
    while (j>=0)
    {
        aux[k++] = Y[j--];
    }
    return aux;
    
}
