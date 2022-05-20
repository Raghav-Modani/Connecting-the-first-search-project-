#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

//assuming maximum number of nodes to be 10^5
bool vis[100001]; // visited array for storing if a vertex is visited or not
vector <int> g[100001];
int n,m; //n is number of nodes and m is number of edges.
vector <int> comp; // comp[v] return the id of the connected component which belongs to v
int answer=0; // the number of connected components

//dfs fuction
void dfs(int v){
    vis[v]=true; //marked v as true when entered into it
    // run loop for every child of v
    for(int child : g[v]){
        // if child is not visited then call dfs on it
        if(!vis[child]){
            comp[v] = answer+1;
            dfs(child);
        }
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
    comp.assign(n,-1);
    for(int v = 0;v<n;v++){
        // calling dfs for every node if it is not visited
        if(!vis[v]){
            dfs(v);
            answer++;
        }
    }

    cout<<"Number of connected components: "<<answer<<"\n";
    int v; // any node v whose connected component is to be found
    cin>>v;
    cout<<comp[v]; // connected component of v

    // the vector which maps each node to its component is 'comp'.

    return 0;
}
