// Rat in a Maze.

#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int newx, int newy, vector < vector < bool > > visited, vector < vector< int > > arr , int n){
    if( (newx >= 0 && newx < n) && (newy >= 0 && newy < n) &&
        visited[newx][newy] != 1 && arr[newx][newy] == 1){
        return true;
    }
    else{
        return false;
    }
}

void solveMaze(int x, int y, vector < vector < int > > &arr, int n, vector<string> ans, vector <vector < bool > > visited, string path){
    
    // base case
    if(x==n-1 && y==n-1){
        ans.push_back(path);
    }

    // 4 movement
    // D, L, R, U

    // Down
    if(isSafe(x+1, y, visited, arr, n)){
        visited[x][y] = 1;
        solveMaze(x+1,y,arr,n,ans,visited,path + 'D');
    }

    // Left
    if(isSafe(x, y-1, visited, arr, n)){
        visited[x][y] = 1;
        solveMaze(x,y-1,arr,n,ans,visited,path + 'D');
    }

    // Right
    if(isSafe(x, y+1, visited, arr, n)){
        visited[x][y] = 1;
        solveMaze(x,y+1,arr,n,ans,visited,path + 'D');
    }

    // Up
    if(isSafe(x-1, y, visited, arr, n)){
        visited[x][y] = 1;
        solveMaze(x-1,y,arr,n,ans,visited,path + 'D');
    }

    visited[x][y] = 0; 

}

vector<string> SearchMaze(vector < vector < int > > &arr, int n){
    vector<string> ans;
    vector< vector <bool> > visited (n,vector < bool > (n,0));
    string path = "";

    if(arr[0][0] == 0){
        return ans;
    }

    solveMaze(0,0,arr,n,ans,visited,path);
    return ans;
}

int main(){

    vector<vector<int> > arr;
    arr.push_back(vector<int>{1, 0, 0, 0});
    arr.push_back(vector<int>{1, 1, 0, 1});
    arr.push_back(vector<int>{1, 1, 0, 0});
    arr.push_back(vector<int>{0, 1, 1, 1});
    int n = arr.size();

    SearchMaze(arr,n);
 
    return 0;
}