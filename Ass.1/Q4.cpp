#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

//assuming maximum number of nodes to be 10^5
bool vis[100001]; // visited array for storing if a vertex is visited or not
vector <int> g[100001];
int n,m; //n is number of nodes and m is number of edges.
bool cycle = false; 

//dfs fuction
void dfs(int v,int parent){
    vis[v]=true; //marked v as true when entered into it
    // run loop for every child of v
    for(int child : g[v]){
        if(child == parent) continue;
        if(vis[child]){
            cycle = true;
            return;
        }
        if(!vis[child])
            dfs(child,v);
    }
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
    for(int v = 0;v<n;v++){
        // calling dfs for every node if it is not visited
        if(!vis[v]){
            dfs(v,-1);
        }
    }
    if(cycle)
        cout<<"Cycle present";
    else
        cout<<"Cycle not present";


    return 0;
}
