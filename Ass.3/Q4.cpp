#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;
vector <long long> bit;
int n;

void add(int i,int delta){
  for(;i<=n;i += i&-i)
    bit[i] += delta;
}

long long sum(int i){
  long long res=0;
  for(;i>0;i -= i&-i)
    res += bit[i];
  return res;
}

int main(){     

  // #ifndef ONLINE_JUDGE
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  // #endif

  int q;
  cin>>n>>q;
  bit.assign(n+1,0);
  int arr[n+1];
  for(int i=1;i<=n;i++){
    cin>>arr[i];
    add(i,arr[i]);
  }
  while(q--){
    int type;
    cin>>type;
    if(type==1){
      int k,u;
      cin>>k>>u;
      add(k,-arr[k]);
      arr[k] = u;
      add(k,arr[k]);
    }
    else{
      int a,b;
      cin>>a>>b;
      cout<<sum(b)-sum(a-1)<<"\n";
    }
  }
  
  
  return 0;
    
}
