//--------------//
//  Ahmed Dinar //
//  CSE, JUST   //
//--------------//
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<limits>

using namespace std;

#define filein       freopen("in.txt","r",stdin)
#define fileout      freopen("out.txt","w",stdout)

#define MS(x,v)      memset(&x,v,sizeof(x))
#define CL(x)        memset(&x,0,sizeof(x))
#define mp           make_pair
#define pb           push_back
#define sz           size()
#define cl           clear()
#define ss           second
#define fi           first

#define vanish       scanf("\n")
#define nl           puts("")
#define endl         '\n'
#define i64          long long
#define all(x)       x.begin(),x.end()

#define Iterate(s)   for(typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define FOR(i,k,n)   for(__typeof(n) i = (k); i <= (n); ++i)
#define For(i,k,n)   for(__typeof(n) i = (k); i < (n); ++i)
#define ROF(i,k,n)   for(__typeof(n) i = k; i >= n; i--)
#define REP(i,n)     for(__typeof(n) i = 0; i < (n); ++i)

#define MAX          405
#define oo           1000000000000
#define MOD          1000000007

map<int,pair<int,int> >ans;
vector<int>s;
int vis[MAX*2];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);


    int n;
    cin>>n;

    vis[1] = -1;
    FOR(i,2,2*n){
        vis[i] = -1;
        FOR(j,1,i-1){
            int x;
            cin>>x;
            ans[x] = mp(i,j);
            s.pb(x);
        }
    }

    sort(all(s));

    for(int i=s.sz-1; i>=0; i--){
       // cout << s[i] << " " << ans[s[i]].fi << " " << ans[s[i]].ss << endl;
        if( vis[ans[s[i]].fi]==-1 && vis[ans[s[i]].ss]==-1 ){
            vis[ans[s[i]].fi] = ans[s[i]].ss;
            vis[ans[s[i]].ss] = ans[s[i]].fi;
        }
    }

    FOR(i,1,2*n) cout << vis[i] <<  " ";


    return 0;
}

















