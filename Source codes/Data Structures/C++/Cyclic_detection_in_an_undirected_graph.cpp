#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, pair<int, int>> ppi;
const int N = 1e5 + 10;

bool vis[N];
vector<int> graph[N];

bool dfs(int vertex, int par)
{

    vis[vertex] = true;
    bool isLoopExists = false;
    for (int child : graph[vertex])
    {
       if(vis[child] && child == par)
       continue;

        if (vis[child])
            return true;
       isLoopExists |= dfs(child,vertex);

    }
    return isLoopExists;
}

/*Significance of isLoopExists is that if one node return false and the other node returns true then eventually a cycle does exist in the graph*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    // n is number of nodes and m is number of edges

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1); // since this is an undirected graph.
    }
    
    bool isloopexists = false;

    for (int i = 1; i <= n; i++)
    {
        if(vis[i])continue;
        if(dfs(i,0))
        {
            isloopexists = true;
            break;
        }
    }
    
    cout<<isloopexists<<endl;

    return 0;
}