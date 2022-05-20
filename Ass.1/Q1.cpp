#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

//assuming maximum number of nodes to be 10^5
bool vis[100001]; // visited array for storing if a vertex is visited or not
vector <int> g[100001];
vector<int> tin; // tin[v] stores the entry time of vertex v
vector <int> tout; // tout[v] stores the exit time of vertex v
vector <int> parent; //parent[v] stores the parent of vertex v
int n,m; //n is number of nodes and m is number of edges.
int timer=0;

//dfs fuction
void dfs(int v){
    vis[v]=true; //marked v as true when entered into it
    tin[v] = timer++;
    // run loop for every child of v
    for(int child : g[v]){
        // if child is not visited then call dfs on it
        if(!vis[child]){
            parent[child] = v;
            dfs(child);
        }
    }
    tout[v] = timer++;
}

// function which when given edge (u, v) classifies it into tree edge(T) or back edge(B).

char edge_type(int u,int v){
    if(parent[v] == u) // if the edge occurs in dfs tree then its tree edge
        return 'T';
    if(tin[v] < tin[u] && tout[v] > tout[u])
        return 'B';
}

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
    parent.assign(n,-1);
    tin.assign(n,-1);
    tout.assign(n,-1);
    for(int v = 0;v<n;v++){
        // calling dfs for every node if it is not visited
        if(!vis[v])
            dfs(v);
    }

    int u,v;//edge (u,v)
    cin>>u>>v;
    cout<<edge_type(u,v);

    return 0;
}
