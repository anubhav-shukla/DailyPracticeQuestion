void allpath(vector<vector<int>> &ans,stack<int> &st,vector<vector<int>>& graph,int &n)
    {
        if(st.top()==n-1)                       //if arrive the n-1 
        {
            vector<int> path;                   //we get the right path
            stack<int> copy_st=st;              //copy the stack to get the path
            while(!copy_st.empty())
            {
                path.push_back(copy_st.top());
                copy_st.pop();
            }
            reverse(path.begin(),path.end());   //reverse the elem which is in stack-order
            ans.push_back(path);                //another answer
            return;
        }
        else
        {
            int top_point=st.top();             //from this point
            //if this point cannot go to anywhere ,we can clear it
            if(graph[top_point].size()==0) 
            {
                while(st.top()!=0)
                    st.pop();
                return ;
            }
            //from this point, we can go to the next point
            for(int i=0;i<graph[top_point].size();i++)
            {
                st.push(graph[top_point][i]);
                allpath(ans,st,graph,n);
                st.pop();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<vector<int>> ans;
        stack<int> st;      //stack for dps
        st.push(0);         //start point is 0
        allpath(ans,st,graph,n);
        return ans;
    }