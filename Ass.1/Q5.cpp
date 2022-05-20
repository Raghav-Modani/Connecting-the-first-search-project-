#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

//assuming maximum number of nodes to be 10^5
bool vis[100001]; // visited array for storing if a vertex is visited or not
vector <int> g[100001];
int n,m; //n is number of nodes and m is number of edges.
int timer=0;
int tin[100001]; //tin[v] stores the entry time of vertex v 
int low[100001]; // low[v] stores the smallest entry time of the vertex that can be reached form vertex v

//function to delete (a,b) edge....here marker used for deleting is -1
void delete_edge(int a,int b){
    for(int i=0;i<g[a].size();i++)
        if(g[a][i] == b){
            g[a][i] = -1;
            break;
        }
    for(int i=0;i<g[b].size();i++)
        if(g[b][i] == a){
            g[b][i] = -1;
            break;
        }    
}


//dfs fuction
void dfs(int v,int parent){
    vis[v]=true; //marked v as true when entered into it
    tin[v] = low[v] = timer++;
    // run loop for every child of v
    for(int child : g[v]){
        if(child==parent) continue;
        if(vis[child]){
            low[v] = min(low[v],tin[child]);
        }
        if(!vis[child]){
            dfs(child,v);
            low[v] = min(low[v],low[child]);
            if(low[child] > tin[v]) // (child,v) is a bridge so delete it
                delete_edge(child,v);
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
    for(int v = 0;v<n;v++){
        // calling dfs for every node if it is not visited
        if(!vis[v]){
            dfs(v,-1);
        }
    }
    // final adjacency list after marking removed edges as -1
    // for(int i=0;i<n;i++){
    //     for(auto it=g[i].begin();it!=g[i].end();it++)
    //         cout<<*it<<" ";
    //     cout<<"\n";
    // }

    return 0;
}
