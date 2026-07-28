#include<bits/stdc++.h>
using namespace std;
char board[4][4];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int s=1;s<=3;s++)
            for(int t=1;t<=3;t++)
                cin>>board[s][t];     
        int flag=0;
        for(int j=1;j<=3;j++)
        {
            if(board[j][1]==board[j][2]&&board[j][2]==board[j][3]&&board[j][1]!='.'){
                flag=1;
                cout<<board[j][1]<<endl;
                break;
            }
            if(board[1][j]==board[2][j]&&board[2][j]==board[3][j]&&board[1][j]!='.')
            {
                flag=1;
                cout<<board[1][j]<<endl;
                break;
            }
        }
        if(flag) continue;
        if(board[1][1]==board[2][2]&&board[2][2]==board[3][3]&&board[1][1]!='.'){
                flag=1;
                cout<<board[1][1]<<endl;
                continue;
         }
         if(board[1][3]==board[2][2]&&board[2][2]==board[3][1]&&board[1][3]!='.'){
                flag=1;
                cout<<board[1][3]<<endl;
                continue;
         }
         cout<<"ongoing"<<endl;


    }
}