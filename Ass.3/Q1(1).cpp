#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;
vector <int> parent;
vector <int> Rank;

int find_set(int v){
  if(v==parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

int main(){     

  // #ifndef ONLINE_JUDGE
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  // #endif

  int n,m;
  cin>>n>>m;
  parent.assign(n+1,0);
  Rank.assign(n+1,0);
  for(int i=1;i<=n;i++){
    parent[i] = i;
  }

  while(m--){
    string str;
    cin>>str;
    if(str=="union"){
      int u,v;
      cin>>u>>v;
      u = find_set(u);
      v = find_set(v);
      if(u!=v){
        if(Rank[u]<Rank[v])
          swap(u,v);
        parent[v] = u;
        if(Rank[u]==Rank[v])
          Rank[u]++;
      }
    }
    if(str=="get"){
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
