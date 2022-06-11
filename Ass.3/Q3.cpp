#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;
vector <int> parent;
vector <int> size;

int find_set(int v){
  if(v==parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int u,int v){
  u = find_set(u);
  v = find_set(v);
  if(u!=v){
    if(size[u]<size[v])
      swap(u,v);
    parent[v] = u;
    size[u] += size[v];
  }
}


int main(){     

  // #ifndef ONLINE_JUDGE
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  // #endif

  int n,m;
  cin>>n>>m;
  parent.assign(n+1,0);
  size.assign(n+1,1);
  for(int i=1;i<=n;i++){
    parent[i] = i;
  }
  vector <pair<int,pair<int,int> > > edges; //edges.first stores the weight of the edges , which will be used to sort the weights and edges.second will be a pair storing the vertices of that edge
  for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    edges.push_back({w,{u,v}});
  }
  sort(edges.begin(),edges.end());

  long long min_wt = 0;
  for(auto edge : edges){
    int w = edge.first;
    int u = edge.second.first;
    int v = edge.second.second;
    if(find_set(u)==find_set(v)) continue;
    union_sets(u,v);
    min_wt += w;
  }
  cout<<min_wt;

  
  
  return 0;
    
}
