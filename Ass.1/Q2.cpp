#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

bool vis[100001]; // visited array for storing if a vertex is visited or not
vector <int> g[100001];
int distance[100001]; //distance[v] stores the distance of v from the source vertex s
int n,m; //n is number of nodes and m is number of edges.

int main(){


	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt","r",stdin);
 //    freopen("output.txt","w",stdout);
 //    #endif

    cin>>n>>m;
    for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            // inserting the edges between a and b in the adjacency list
            g[a].push_back(b);
            g[b].push_back(a);
    }
    int s,u; // source vertex and destination vertex
    cin>>s>>u;
    int d[n]={-1};

    queue <int> q;
    q.push(s);
    d[s] = 0;
    vis[s] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int child : g[v]){
            if(!vis[child]){
                q.push(child);
                d[child] = d[v] + 1;
                vis[child] = true;
            }
        }
    }

    cout<<d[u];

    

    return 0;
}
