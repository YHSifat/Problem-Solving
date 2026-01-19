//sol 5369666174
#include<bits/stdc++.h>
using namespace std;

#define mxx 200005
#define ll long long
#define answ ((out)?"YES":"NO")
#define endl '\n'

void solve(int tc){
    int n,a;
    cin>>n;
    
    set <int> st;
    vector<int> vec;

    for(int i=0;i<n;i++){
        cin>>a;
        st.insert(a);
    }

    for(auto it:st){
        vec.push_back(it);
    }
    
    int si=vec.size();
    int out=0,cur=0;
    
    for(int i=1;i<n;i++){
        if(vec[i]==vec[i-1]+1){
            cur++;  
        }else cur=0; 
        out=max(cur,out);

    }

    cout<<out+1<<endl;



    
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
    sub_run();
    cin>>t;
    for(int i=1;i<=t;i++)solve(i);
}


