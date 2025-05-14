#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<int>> maze, vector<vector<bool> > &vis, int n){
    if((newx >=0 && newx < n) && (newy >= 0 && newy < n) && vis[newx][newy] != 1 && maze[newx][newy] == 1){
        return true;
    }
    return false;
}

void solve(int x, int y, vector<vector<int> > &maze, int n, vector<string> &ans, vector<vector<bool> > &vis, string path){
    // base case
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    vis[x][y] = 1;

    // down
    if(isSafe(x+1, y, maze, vis, n)){
        solve(x+1,y,maze,n,ans,vis,path+'D');
    }

    // left
    if(isSafe(x, y-1, maze, vis, n)){
        solve(x,y-1,maze,n,ans,vis,path+'L');
    }

    // right
    if(isSafe(x, y+1, maze, vis, n)){
        solve(x,y+1,maze,n,ans,vis,path+'R');
    }

    // up
    if(isSafe(x-1, y, maze, vis, n)){
        solve(x-1,y,maze,n,ans,vis,path+'U');
    }

    // backtrack
    vis[x][y] = 0;
}

vector<string> RatInAMaze(vector<vector<int> > &maze, int n){
    vector<string> ans;
    vector<vector<bool>> vis(n, vector<bool>(n, 0));
    string path = "";

    solve(0,0,maze,n,ans,vis,path);
    return ans;
}

int main(){

    vector<vector<int> > maze = {
        {1,0,0,0},
        {1,1,0,0},
        {1,1,0,0},
        {0,1,1,1}
    };
    
    int size = 4;

    vector<string> sol = RatInAMaze(maze,size);
    for(int i=0; i<sol.size(); i++){
        cout << sol[i] << endl;
    }

    return 0;
}