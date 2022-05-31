#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;
vector <int> g[100001];
vector <int> g_t[100001]; // stores the transpose of the given graph i.e. all edges reversed
vector <bool> visited(100001);
vector <int> top_order; // stores the topological order of the graph
vector <int> component;
int n,m;

void dsf2(int v){
  visited[v] = true;
  component.push_back(v);
  for(int u :g_t[v]){
    if(!visited[u])
      dsf2(u);
  }
}

void dfs1(int v){
  visited[v] = true;
  for(int u : g[v]){
    if(!visited[u]){
      dfs1(u);
    }
  }
  top_order.push_back(v);
}

int main(){
  
  // #ifndef ONLINE_JUDGE
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  // #endif

  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g_t[b].push_back(a);
  }

  for(int i=1;i<=n;i++){
    if(!visited[i])
      dfs1(i);
  }

  reverse(top_order.begin(),top_order.end());
  visited.assign(100001,false);

  int k=0;// number of connected components are stored in k, initially zero
  vector <int> scc(n+1); //scc[i] maps the vertex i to the SCC it belongs to.
  for(int v : top_order){
    if(!visited[v]){
      dsf2(v);
      k++; // increase in number of SCC
      for(int vertex : component)
        scc[vertex] = k;
      component.clear();
    }
  }
  cout<<k<<"\n";
  for(int i=1;i<=n;i++)
    cout<<scc[i]<<" ";

  return 0;
}
