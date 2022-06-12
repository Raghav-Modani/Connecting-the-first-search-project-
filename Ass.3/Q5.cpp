#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;
vector <long long> bit1; //bit1[i] is the normal bit array which stores the sum of values of some ranges
vector <long long> bit2; //bit2 is an array used for updating the range and then adding the new value to the old value of array stored in bit1.
int n;

void add(int i,int delta,vector<long long> &a){
  for(;i<=n;i += i&-i)
    a[i] += delta;
}

void range_add(int l,int r,int u){
  add(l,u,bit2);
  add(r+1,-u,bit2);
}

long long sum(int i,vector<long long> &a){
  long long res=0;
  for(;i>0;i -= i&-i)
    res += a[i];
  return res;
}

int main(){     

  // #ifndef ONLINE_JUDGE
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  // #endif

  int q;
  cin>>n>>q;
  bit1.assign(n+1,0);
  bit2.assign(n+1,0);
  int arr[n+1];
  for(int i=1;i<=n;i++){
    cin>>arr[i];
    add(i,arr[i],bit1);
  }
  while(q--){
    int type;
    cin>>type;
    if(type==1){
      int a,b,u;
      cin>>a>>b>>u;
      range_add(a,b,u);
    }
    else{
      int k;
      cin>>k;
      cout<<sum(k,bit1)-sum(k-1,bit1)+sum(k,bit2)<<"\n";
    }
  }
  
  return 0;
    
}
