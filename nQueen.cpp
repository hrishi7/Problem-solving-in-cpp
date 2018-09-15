#include<iostream>
using namespace std;


bool isSafe(int board[][10], int i, int j, int n){
  for(int row = 0; row<i; row++){
    if(board[row][j] == 1){
      return false;
    }
  }
  int x = i;
  int y = j;
  while(x >=0 && y >=0){
    if(board[x][y] == 1)
      return false;
    x--;y--;
  }
  x = i; y = j;
  while(x >=0 && y <=n){
    if(board[x][y] == 1)
      return false;
    x--;y++;
  }
  return true;
}

bool solveNQueen(int board[][10], int i, int n){
  //Base Case
  if(i == n){
    for(int i = 0; i<n; i++){
      for(int j = 0; j<n; j++){
        if(board[i][j] == 1){
            cout<<"Q ";
        }
        else{
            cout<<"_ ";
        }
      }
      cout<<endl;
    }
    cout<<endl;
    return false;
  }
  for(int j = 0; j<n; j++){
    if(isSafe(board, i, j, n)){
      board[i][j] = 1;
      bool nextQueenPlaced = solveNQueen(board, i+1, n);
      if(nextQueenPlaced){
        return true;
      }
      board[i][j] = 0;
    }
  }
  return false;
}

void placeNQueens(int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
  int board[10][10] = {0};

  solveNQueen(board, 0, n);


}

int main()
{
    placeNQueens(8);
}

