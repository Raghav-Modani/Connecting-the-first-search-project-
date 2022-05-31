#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;
vector <int> g[100001];
vector <int> top_order; //stores the topological order
vector <bool> visited;
int n,m;

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
  }
  
  int inDeg[n+1]={0};
  queue<int> q;
  for(int i=1;i<=n;i++){
    for(int v : g[i])
      inDeg[v]++;
  }

  for(int i=1;i<=n;i++)
    if(inDeg[i]==0)
      q.push(i);

  int count = 0;

  while(!q.empty()){
    int v = q.front();
    q.pop();
    top_order.push_back(v);
    for(int child : g[v]){
      inDeg[child]--;
      if(inDeg[child]==0)
        q.push(child);
    }
    count++;
  }
  // if all vertices are not added to the count implies that there is a cycle hence no topological order exists.
  if(count!=n){
    cout<<"IMPOSSIBLE";
    return 0;
  }
  // printing the topplogical oder
  for(int v:top_order)
    cout<<v<<" ";
  return 0;
}
