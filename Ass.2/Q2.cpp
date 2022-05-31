#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;
vector <int> g[100001];
vector <int> g_t[100001]; // stores the transpose of the given graph i.e. all edges reversed
vector <int> top_order; // stores the topological order of the graph
vector <bool> visited(100001);
const int M = 1e9+7;
int n,m;

void shortest_path_length(int u,int v){
  vector <bool> used(n+1);
  vector <int> d(n); // d[i] stores the shortest distance from source to i , all d[i] initialized to zero.
  queue <int> q;
  q.push(u);
  used[u] = true;
  while(!q.empty()){
    int a = q.front();
    q.pop();
    for(int child : g[a]){
      if(!used[child]){
        used[child] = true;
        q.push(child);
        d[child] = d[a]+1;
      }
    }
  }
  cout<<"The length of shortest path between specified vertices is: "<<d[v]<<"\n";
}

void longest_path_length(int source,int destination){
  int d[n+1]; // d[i] stores the length of the longest path from u to destination vertex
  for(int i=0;i<n+1;i++)
    d[i] = INT_MIN;//initializing all the length to negative infinity
  d[source] = 0; // making the length of the node 'u' from itself equals to zero.
  for(auto a : top_order){
    for(int b : g[a])
      if(d[b]<d[a]+1){
        d[b] = d[a] + 1;
      }
  }
  cout<<"The length of longest path between specified vertices is: "<<d[destination]<<"\n"; // 'v' is the final destination from 'u' ,so d[v] + 1 is the length of the longest path from u to v.

}

void number_of_paths(int u,int v){
  int dp[n+1]={0}; // dp[i] stores the number of paths from i to destination
  dp[v] = 1; // there is only one path from v to itself
  //iterate in reverse order of topological sort  
  for(auto it = top_order.rbegin();it!=top_order.rend();it++){
    for(int child : g[*it])
      dp[*it] = (dp[*it]%M + dp[child]%M)%M;
  }
  cout<<"The number of paths between specified vertices are: "<<dp[u]<<"\n";
}

void dfs(int v){
  visited[v] = true;
  for(int u : g[v]){
    if(!visited[u]){
      dfs(u);
    }
  }
  top_order.push_back(v);
}

int main(){
  
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  int u,v;//u and v are the given vertices
  cin>>n>>m>>u>>v;
  // reading the graph
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g_t[b].push_back(a);
  }
  // given that there always exists a path from u to v so not applying the condition to check if the path actually exists.

  // starting the dfs from the source node as 'u'
  for(int i=u;i<=n;i++)
    if(!visited[i]){
      dfs(i);
    }

  reverse(top_order.begin(),top_order.end());
  shortest_path_length(u,v);
  longest_path_length(u,v);
  number_of_paths(u,v);


  return 0;
}
