//sol 5369666174
#include<bits/stdc++.h>
using namespace std;

#define mxx 200005
#define ll long long
#define answ ((out)?"YES":"NO")
#define endl '\n'

vector<int> vec,pref;
int n,q,cur;


int recur(int pos, int pow, int score, int h){
    if(pow==n)return h;
    
    int apos=pos*pow;

    if(pos%2){
        if(apos-pow-1>=0)cur=pref[apos-1]^pref[apos-pow-1];
        else cur=pref[apos-1];
    }else{
        cur=pref[apos+2*pow-1]^pref[apos+pow-1];
    }
    int inc=pow;
    if(cur>score ||(cur==score && pos%2)){
        inc=0;
    }


    
    return recur(pos/2,pow*2,score^cur,h+inc);
    


}




void solve(int tc){
    cin>>n>>q;
    n=1<<n;
    vec.resize(n);
    pref.resize(n);
    for(auto &it:vec)cin>>it;
    pref[0]=vec[0];
    for(int i=1;i<n;i++){
        pref[i]=pref[i-1]^vec[i];
    }


    int pos,score;
    for(int i=0;i<q;i++){
        cin>>pos>>score;
        cout<<n-recur(pos-1,1,score,1)<<endl;
    }


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

