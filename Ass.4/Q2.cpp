#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;
vector <pair<int,int> > g[100005];//g[i].first sotres the node to which 'i' is connected and second element stores the distance.
int n,m;
const int M = 1e9+7;


int main(){
  
  // #ifndef ONLINE_JUDGE
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  // #endif

  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    g[a].push_back({b,c});
  }
  long long dist[n+1];
  int min_flights[n+1],max_flights[n+1],route[n+1];
  for(int i=1;i<=n;i++){
    dist[i] = LLONG_MAX;
    min_flights[i] = INT_MAX;
    max_flights[i] = INT_MIN;
    route[n+1] = 0;
  }
  dist[1] = 0;
  max_flights[1] = 0;
  min_flights[1] = 0;
  route[1] = 1;

  multiset <pair<long long,int> > s;
  s.insert({0,1});
  while(!s.empty()){
    int v = s.begin()->second;
    long long d_v = s.begin()->first;
    s.erase(s.begin());
    if(d_v>dist[v]) continue;
    for(auto edge : g[v]){
      int child = edge.first;
      int wt = edge.second;
      if(dist[child] > dist[v]+wt){
        dist[child] = dist[v] + wt;
        route[child] = route[v];
        min_flights[child] = min_flights[v]+1;
        max_flights[child] = max_flights[v]+1;
        s.insert({dist[child],child});
      }
      else if(dist[child] == dist[v]+wt){
        route[child] = (route[child]%M + route[v]%M)%M;
        min_flights[child] = min(min_flights[child],min_flights[v]+1);
        max_flights[child] = max(max_flights[child],max_flights[v]+1);
      }
    }
  }
  cout<<dist[n]<<" "<<route[n]<<" "<<min_flights[n]<<" "<<max_flights[n];
  
  return 0;
}