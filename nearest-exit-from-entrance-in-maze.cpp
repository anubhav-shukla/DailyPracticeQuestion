



#include <bits/stdc++.h>
using namespace std; 

 int nearestExit(vector<vector<char>>& mat , vector<int>& e ) {
        int n=mat.size() , m=mat[0].size() ;
        vector<int> dx = {1,-1,0,0} , dy = {0,0,1,-1} ;
        vector<vector<int>> vis(n , vector<int>(m,0)) ;
        queue<pair<pair<int,int> , int>> q ;

        q.push({ {e[0] , e[1]} , 0}) ;
        vis[e[0]][e[1]]=1 ;
        
        while(!q.empty())
        {
            auto cur = q.front().first ;
            auto d = q.front().second ;
            q.pop() ;
            int curx = cur.first , cury = cur.second ;
            
            for(int i=0 ; i<4 ; i++)
            {
                int nx = curx+dx[i] , ny = cury+dy[i] ;
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || mat[nx][ny] == '+' || vis[nx][ny])  continue ;
                vis[nx][ny]=1 ;
                q.push({{nx,ny} , d+1}) ;
                if((nx == n-1 || nx == 0 || ny == m-1 || ny == 0))  return d+1 ;
            }
        }
        return -1 ;
    }


    