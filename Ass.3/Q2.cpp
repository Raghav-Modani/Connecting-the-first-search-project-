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
  }

  vector <pair<string,pair<int,int> > > queries;
  vector <string> ans;
  for(int i=0;i<k;i++){
    string str;
    int u,v;
    cin>>str>>u>>v;
    queries.push_back({str,{u,v}});
  }
  reverse(queries.begin(),queries.end());
  for(auto p : queries){
    string str = p.first;
    int u = p.second.first;
    int v = p.second.second;
    if(str=="cut")
      union_sets(u,v);
    else{
      if(find_set(u)==find_set(v))
        ans.push_back("YES");
      else
        ans.push_back("NO");
    }
  }
  reverse(ans.begin(),ans.end());
  for(string str : ans)
    cout<<str<<"\n";
  
  return 0;
    
}
