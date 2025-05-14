// N-Queen Problem.

#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int> > &board, int n){
    int x = row;
    int y = col;
    
    while(y>=0){
        if(board[x][y] == 1){
            return false;
        }
        y--;
    }

    // Checking Diagonals.
    x = row;
    y = col;
    
    // 1. Upper Diagonal.
    while(x>=0 && y>=0){
        if(board[x][y] == 1){
            return false;
            y--;
            x--;
        }
    }

    // 2. Lower Diagonal
    while(x<0 && y>=0){
        if(board[x][y] == 1){
            return false;
            y--;
            x++;
        }
    }
    return true;
}

void addSolution(vector<vector<int> > &board, vector<vector<int> > &ans, int n){
    
    vector<int> temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }
    
    ans.push_back(temp);

    // ans.push_back(board);
}

void solve(int col, vector<vector<int> > &board, vector<vector<int> > &ans, int n){
    
    // base case
    if(col == n){
        addSolution(board,ans,n);
        return;
    }

    // Solving one case and rest for recursion.
    for(int row = 0; row < n; row++){
        if(isSafe(row,col,board,n)){
            // place Queen here.
            board[row][col] = 1;
            solve(col+1,board,ans,n);

            // backtrack
            board[row][col] = 0;
        }
    }
}

vector<vector<int> > nQueens(int n){
    vector<vector <int> >board(n,vector<int>(n,0));
    vector<vector <int> >ans;

    solve(0,board,ans,n);
}

int main(){

    int n = 4;
    nQueens(n);

    return 0;
}