//sol 5369666174
#include<bits/stdc++.h>
using namespace std;

#define mxx 200005
#define ll long long
#define answ ((out)?"YES":"NO")
#define endl '\n'


void solve(int tc){
   ll n,m,h;
   cin>>n>>m>>h;
   std::vector<ll> ori(n),vec;

   for(auto &it:ori)cin>>it;

   vec=ori;
   
   vector<int>rst(n,0);
   ll counter=0;
   ll a,b;
   for(int i=0;i<m;i++){
      cin>>a>>b;
      a--;

      if(rst[a]!=counter){
         vec[a]=ori[a];
         rst[a]=counter;
      }

      vec[a]+=b;

      if(vec[a]>h)counter++;
   }

   for(int i=0;i<n;i++){
      if(rst[i]!=counter)vec[i]=ori[i];
   }

   for(auto &it:vec)cout<<it<<" ";
   cout<<endl;

   


}







 void sub_run(){
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t=1;
    // sub_run();
    cin>>t;
    for(int i=1;i<=t;i++)solve(i);
}

