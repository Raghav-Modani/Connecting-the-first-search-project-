#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;
vector <int> g[200002];
vector <int> g_t[200002]; // stores the transpose of the given graph i.e. all edges reversed
vector <bool> visited(200002);
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
  for(int i=0;i<n;i++){
    int a,b;
    char c1,c2;
    cin>>c1>>a;
    cin.ignore();
    cin>>c2>>b;
    // complement of x is stored as m+x in the graph array since index of array can't be negative
    if(c1=='+' && c2=='+'){
      g[m+a].push_back(b);
      g[m+b].push_back(a);
      g_t[b].push_back(m+a);
      g_t[a].push_back(m+b);
    }
    else if(c1=='-' && c2=='+'){
      g[a].push_back(b);
      g_t[b].push_back(a);
      g[m+b].push_back(m+a);
      g_t[m+a].push_back(m+b);
    }
    else if(c1=='+' && c2=='-'){
      g[m+a].push_back(m+b);
      g_t[m+b].push_back(m+a);
      g[b].push_back(a);
      g_t[a].push_back(b);
    }
    else{
      g[a].push_back(m+b);
      g_t[m+b].push_back(a);
      g[b].push_back(m+a);
      g_t[m+a].push_back(b);
    }
  }

  for(int i=1;i<=2*m;i++){
    if(!visited[i])
      dfs1(i);
  }

  reverse(top_order.begin(),top_order.end());
  visited.assign(100001,false);

  int k=0;// number of connected components are stored in k, initially zero
  vector <int> scc(2*m+1); //scc[i] maps the vertex i to the SCC it belongs to.
  for(int v : top_order){
    if(!visited[v]){
      dsf2(v);
      k++; // increase in number of SCC
      for(int vertex : component)
        scc[vertex] = k;
      component.clear();
    }
  }
  // cout<<k<<"\n";
  // for(int i=1;i<=2*m;i++)
  //   cout<<scc[i]<<" ";
  vector <char> ans(m+1);
  for(int i=1;i<=m;i++){
    if(scc[i] == scc[i+m]){
      cout<<"IMPOSSIBLE";
      return 0;
    }
    ans[i] = scc[i]>scc[i+m] ? '+' : '-';
  }
  for(int i=1;i<=m;i++)
    cout<<ans[i]<<" ";

  return 0;
}
