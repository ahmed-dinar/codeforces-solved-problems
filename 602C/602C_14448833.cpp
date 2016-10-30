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
#define fileout      freopen("out2.txt","w",stdout)

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
#define sq(x)        (x*x)

#define EPS          0.0000001
#define MAX          403
#define oo           10000000
#define MOD          1000000007

#define PI           acos(-1.0)

int p[MAX][MAX];
vector<int>g[MAX],g1[MAX];
int d[MAX],d1[MAX];

int main(){

     ios_base::sync_with_stdio(0); cin.tie(0);



    int n,m,u,v;
    cin>>n>>m;

    CL(p);

    REP(i,m){
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
        p[u][v] = p[v][u] = 1;
    }


    FOR(i,1,n){
        d[i] = oo;
        d1[i] = oo;
        FOR(j,1,n){
            if( i!=j && p[i][j] == 0 ){
                g1[i].pb(j);
                g1[j].pb(i);
                p[i][j] = p[j][i] = 1;
            }
        }
    }

    queue<int>q;
    q.push(1);
    d[1] = 0;
    while(q.size()){
        u = q.front();
        q.pop();
        REP(i,g[u].sz){
            v = g[u][i];
            if( d[v] > d[u] + 1 ){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    while(q.size()) q.pop();

    q.push(1);
    d1[1] = 0;
    while(q.size()){
        u = q.front();
        q.pop();
        REP(i,g1[u].sz){
            v = g1[u][i];
            int x = d1[u] + 1;
            if( x == d[v] ){
                x+=2;
            }
            if( d1[v] > x ){
                d1[v] = x;
                q.push(v);
            }
        }
    }

    if( d1[n] == oo || d[n] == oo ) cout << "-1" << endl;
    else cout << max(d1[n],d[n]) << endl;

    return 0;
}

