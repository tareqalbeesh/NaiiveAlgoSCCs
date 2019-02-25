#include <bits/stdc++.h>
using namespace std;
vector < vector <int > > V(1001);
vector < vector <int > > SCC(1001);

vector <vector <int > > Reachable(1001);

vector <bool> visited(1001);


void find_reachable_using_DFS(int  i,int curr)
{
    Reachable[i].push_back(curr);
    visited[curr] = 1;
    for(int j=0;j<V[curr].size();j++)
    {
        if(!visited[V[curr][j]])
        {
            find_reachable_using_DFS(i , V[curr][j]);
        }
    }
}

void fill_reachables(int n)
{
    for(int i = 0 ;i< n;i ++ )
    {
        find_reachable_using_DFS(i,i);
        std::fill(visited.begin(), visited.end(), 0);
    }
}
void print_reachables(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<Reachable[i].size();j++)
        {
            cout << Reachable[i][j] << " ";
        }
        cout << endl;
    }
}
void print_SCCs(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<SCC[i].size();j++)
        {
            cout << SCC[i][j] << " ";
        }
        cout << endl;
    }
}
bool is_reacable(int from ,int to )
{
        for(int i=0;i<Reachable[from].size();i++)
        {
            if(Reachable[from][i]==to)
                return true;
        }
        return false;
}
void find_scc(int n)
{
for(int i = 0;i<n;i++)
{
    for(int j=0;j<Reachable[i].size();j++)
    {
        if(is_reacable(Reachable[i][j],i))
        {
                SCC[i].push_back(Reachable[i][j]);
        }
    }
}
}

main()
{
    int n,m,x,y;
    cin >> n >> m ;
    for(int i=0;i<m;i++)
    {
        cin >> x  >> y;
        V[x].push_back(y);
    }
    fill_reachables(n);
    find_scc(n);
    print_SCCs(n);


/*
8 13
1 0
2 1
2 3
3 6
6 7
7 6
5 6
5 4
5 1
4 0
0 5
0 8
7 8

*/






}
