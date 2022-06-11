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

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  int n,m,k;
  cin>>n>>m>>k;
  parent.assign(n+1,0);
  size.assign(n+1,1);
  for(int i=1;i<=n;i++){
    parent[i] = i;
  }

  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    union_sets(u,v);
  }

  while(k--){
    string str;
    cin>>str;
    if(str=="cut"){
      int u,v;
      cin>>u>>v;
      parent[v] = v;
    }
    if(str=="ask"){
      int u,v;
      cin>>u>>v;
      u = find_set(u);
      v = find_set(v);
      if(u==v)
        cout<<"YES\n";
      else
        cout<<"NO\n";
    }
  }
  
  return 0;
    
}
