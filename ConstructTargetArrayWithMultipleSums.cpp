  #include <bits/stdc++.h>
   using namespace std;
  
 bool isPossible(vector<int>& target) 
    {
        priority_queue<int> q(target.begin(),target.end());
        long  total=0;
        for(int &n:target)
        {
            total+=n;
        }
        while(true)
        {
            int a=q.top();
            q.pop();
            total-=a;
            if(a==1||total==1)
                return true;
            if(a<total||total==0||a%total==0)
                return false;
            a%=total;
            total+=a;
            q.push(a);
        }
        
    }
    int main(){
      vector<int> vect;
 
    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);
 
        isPossible(vect);


    }