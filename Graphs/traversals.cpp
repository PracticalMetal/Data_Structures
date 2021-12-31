#include <iostream>
#include <queue>

using namespace std;

void BFS(int G[][7], int start, int n)
{
    int i=start;
    queue<int> q;
    int visited[7]={0};

    cout<<i<<" ";
    visited[i]=1;
    q.push(i);

    while(!q.empty())
    {
        int v;
        v=q.front();
        q.pop();

        for(int j=1;j<7;j++)
        {
            if(G[v][j]==1 && visited[j]==0)
            {
                cout<<j<<" ";
                visited[j]=1;
                q.push(j);
            }
        }

    }
}

void DFS(int G[][7], int start, int n)
{
    static int visited[7]={0};
    if(visited[start]==0)
    {
        cout<<start<<" ";
        visited[start]=1;
        for(int i=1;i<n;i++)
        {
            if(G[start][i]==1 && visited[i]==0)
            DFS(G,i,n);
        }
    }
}


int main()
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    DFS(G,1,7);
}