class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        for(int i = 0; i < n; i++){
            for(int j = m - 1; j >= 0; j--){
                if(box[i][j] == '#'){
                    int temp_j = j;
                    while(temp_j + 1 < m && box[i][temp_j + 1] != '*' && box[i][temp_j + 1] != '#'){
                        box[i][temp_j] = '.';
                        box[i][temp_j + 1] = '#';
                        temp_j++;
                    }
                }
            }
        }
        vector<vector<char>> ans;

        for(int j = 0;  j < m; j++){
            vector<char> temp;
            for(int i = n - 1; i >= 0; i--){
                temp.push_back(box[i][j]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        for(int i = 0; i < n; i++){
            for(int j = m - 1; j >= 0; j--){
                if(box[i][j] == '#'){
                    int temp_j = j;
                    while(temp_j + 1 < m && box[i][temp_j + 1] != '*' && box[i][temp_j + 1] != '#'){
                        box[i][temp_j] = '.';
                        box[i][temp_j + 1] = '#';
                        temp_j++;
                    }
                }
            }
        }
        vector<vector<char>> ans;

        for(int j = 0;  j < m; j++){
            vector<char> temp;
            for(int i = n - 1; i >= 0; i--){
                temp.push_back(box[i][j]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};