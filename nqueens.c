#include<stdio.h>
#include<stdlib.h>
int n = 8;
int count = 0;
int board[100][100];


void printboard()
{
    for(int i = 0; i<n;i++)
    {
        for(int j = 0; j<n;j++)
        {
            if(board[i][j]==1)
            {
                printf("Q");
            }
            else {
                printf(".");
            }
        }
          printf("\n");
        
        
    }

    printf("\n");
}

int issafe(int row, int col)
{
    for(int i=0;i<n;i++)
    {
        if(board[row][i]==1)
        {
            return 0;
        }

    }
    for(int j = 0; j<n;j++)
    {
        if(board[j][col]==1)
        {
            return 0;
        }
    }
    for(int i=row, j=col; i>=0 && j>=0; i--,j--)
    {
        if(board[i][j]==1)
        {
            return 0;
        }
    }
    for(int i=row, j=col; i>=0 && j<n; i--,j++)
    {
        if(board[i][j]==1)
        {
            return 0;
        }
    }
    return 1;
}

void solve(int row)
{
    if(row==n)
    {
        printboard();
    }
    
    for(int col=0; col<n;col++)
    {
        if(issafe(row,col))
    {
        board[row][col]=1;
        solve(row+1);
        board[row][col]=0;

    }
    }
    
}

int main()
{
    solve(0);
    return 0;   
}