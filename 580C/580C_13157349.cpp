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

#define MAX          100005
#define oo           100000000LL
#define MOD          1000000007

vector<int>g[MAX];
int cats[MAX];
int d[MAX];
int ans,m;
int k[MAX];
int vis[MAX];

void dfs(int u,int p){

    vis[u] = 1;

    if( cats[u] == 0 ) d[u] = 0;
    else{
        d[u] = d[p] + 1;
    }

    if( k[p]==1 || d[u]>m ) k[u] = 1;

    // cout << p << " -> " << u << " " << d[u] << " " << k[p] << " "  << k[u] << endl;

    int up = 0;
    REP(i,g[u].sz){
        int v = g[u][i];
        if( !vis[v] ){
            up = 1;
            dfs(v,u);
        }
    }

    if( up == 0 ){

        //cout << p << " -> " << u << " " << d[u] << " " << k[u] << endl;
        if( k[u] == 0  ) ans++;
        return;

    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);


//fileout;
    int n;

    cin>>n>>m;

    FOR(i,1,n){
         cin>>cats[i];
         vis[i] = 0;
         k[i] = 0;
         d[i] = 0;
    }

    REP(i,n-1){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    ans = 0;

    dfs(1,1);

    cout << ans << endl;

    return 0;
}

















