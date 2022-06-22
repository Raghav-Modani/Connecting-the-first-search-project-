#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;
int n,m;
vector <bool> visited;
vector <long long> d;
vector <int> parent;
vector <int> cycle;
vector <pair<int,pair<int,int> > > edges;//edges[i].first stores the cost of the edge and the pair edges[i].second stores the vertices it connects.

void bellman_ford(){
  int x;
  for(int i=1;i<=n;i++){
    x = -1;
    for(int j=0;j<m;j++){
      int cost = edges[j].first;
      int a = edges[j].second.first;
      int b = edges[j].second.second;
      if(d[b]>d[a]+cost){
        d[b] = d[a]+cost;
        parent[b] = a;
        visited[b] = true;
        x = b; //stores the vertex if in the nth phase there is relaxation which implies that there is negative cycle
      }
    }
  }

  if(x==-1){
    cout<<"NO";
    return;
  }
  int y = x;
  for (int i=0; i<n; ++i)
  y = parent[y];

  for (int cur=y; ; cur=parent[cur])
    {
      cycle.push_back (cur);
      if (cur == y && cycle.size() > 1)
          break;
    }
  reverse (cycle.begin(), cycle.end());
  cout<<"YES\n";
  for(int e : cycle)
    cout<<e<<" ";
}

int main(){
  
  // #ifndef ONLINE_JUDGE
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  // #endif

  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    edges.push_back({c,{a,b}});
  }
  d.assign(n+1,0);
  parent.assign(n+1,-1);
  visited.assign(n+1,false);
  d[1] = 0;

  bellman_ford();



  return 0;
}