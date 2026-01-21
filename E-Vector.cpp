//sol 5369666174
#include<bits/stdc++.h>
using namespace std;

#define mxx 200005
#define ll long long
#define answ ((out)?"YES":"NO")
#define endl '\n'


void solve(int tc){
   ll n,m,k;
   cin>>n>>m>>k;
   std::vector<ll> rob(n);
   std::vector<ll> spi(m);
   for(auto &it:rob)cin>>it;
   for(auto &it:spi)cin>>it;
   string s;
   cin>>s;

   sort(rob.begin(),rob.end());
   sort(spi.begin(),spi.end());

   vector<pair<ll,ll>>vec;
   ll cur=0;
   for(ll i=0,j=0;i<n;i++){
      while(j<m && spi[j]<rob[i]){
         j++;
      }

      if(j>0)vec.push_back({spi[j-1]-rob[i],i});
      if(j<m){
         vec.push_back({spi[j]-rob[i],i});
      }
   }

   map<ll,ll>mp;

   sort(vec.begin(),vec.end());
   ll sk=vec.size();
   ll init=n-1;
   for(ll i=0;i<sk;i++){
      if(vec[i].first>=0){
         init=i;
         break;
      }
   }
   // for(auto &it:vec){
   //    cout<<it.first<<" "<<it.second<<endl;
   // }
   // cout<<endl;

   ll out=n;
   cur=0;
   ll prevL=0,prevR=0,initL=init,initR=init;
   for(auto &it:s){
      if(it=='L')cur--;
      else cur++;
      // cout<<cur<<"--"<<endl;
      if(cur<prevL){
         prevL=cur;
         for(ll i=initL;i>=0;i--){
            initL=i;
            if(vec[i].first<cur){
               break;
            }else {
               if(cur<=vec[i].first && vec[i].first<=0 && !mp[vec[i].second]){
                  // cout<<cur<<"--"<<vec[i].first<<endl;
                  out--;
                  mp[vec[i].second]=1;
               }
            }
         }
      }else if(cur>prevR){
         prevR=cur;
         for(ll i=initR;i<sk;i++){
            initR=i;
            if(vec[i].first>cur){
               break;
            }else {
               if(cur>=vec[i].first && vec[i].first>=0 && !mp[vec[i].second]){
                  out--;
                  mp[vec[i].second]=1;
               }
            }
         }
      }
      cout<<out<<" ";

   }
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

