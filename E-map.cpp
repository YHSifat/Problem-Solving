//sol 5369666174
#include<bits/stdc++.h>
using namespace std;

#define mxx 200005
#define ll long long
#define answ ((out)?"YES":"NO")
#define endl '\n'


void solve(int tc){
   int n,m,k;
    string s;
    cin>>n>>m>>k;
    std::vector<int> vec(n),spi(m);

    for(auto &it:vec)cin>>it;
    for(auto &it:spi)cin>>it;
    cin>>s;

    sort(vec.begin(),vec.end());
    sort(spi.begin(),spi.end());

    vector<pair<int,int>>pos(n);
    
    map<int,set<int>>mp;

    int dif;
    for(int i=0,j=0;i<n;i++){
        while(j<m && spi[j]<vec[i]){
            j++;
        }
        if(j>0){
            dif=spi[j-1]-vec[i];
            pos[i].first=dif;
            mp[dif].insert(i);
        }
        if(j<m){
            dif=spi[j]-vec[i];
            pos[i].second=dif;
            mp[dif].insert(i);
         }
    }

    int cur=0,alive=n,maxL=0,maxR=0;
    for(int i=0;i<k;i++){
        if(s[i]=='L')cur--;
        else cur++;

        if(cur<0){
         if(cur<maxL)maxL=cur;
         else {
            cout<<alive<<" ";
            continue;
         }
        }else {
         if(cur>maxR)maxR=cur;
         else {
            cout<<alive<<" ";
            continue;
         }
        }

        alive-=mp[cur].size();

        for(auto &it:mp[cur]){
            if(cur!=pos[it].first)mp[pos[it].first].erase(it);
            if(cur!=pos[it].second)mp[pos[it].second].erase(it);
        }
        cout<<alive<<" ";
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

