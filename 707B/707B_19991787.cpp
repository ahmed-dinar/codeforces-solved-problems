/*************\
# Ahmed Dinar #
# CSE,JUST    #
\*************/

#include <bits/stdc++.h>

using namespace std;

#define FI           freopen("in.txt","r",stdin)
#define FO           freopen("out.txt","w",stdout)

#define MS(x,v)      memset(&x,v,sizeof(x))
#define CL(x)        memset(&x,0,sizeof(x))
#define mp           make_pair
#define pb           push_back
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
#define sq(x)        ((x)*(x))

#define PI           acos(-1.0)
#define EPS          0.0000001
#define MOD          1000000007

#define oo           100000000000000LL
#define MAX          100005

struct g
{
    int u,v;
    i64 l;
}gg;

int a[MAX] = {};
vector<g>s;


int main(){

   //FI;

    ios_base::sync_with_stdio(0); cin.tie(0);


    int n,m,k,u,v,p;
    i64 ans = 100000000000LL, l;
    cin >> n >> m >> k;


    REP(i,m){
        cin>>u>>v>>l;
        gg.u = u;
        gg.v = v;
        gg.l = l;
        s.push_back(gg);
    }


    REP(i,k){
        cin>>p;
        a[p] = 1;
    }


    if( k==0 || k>=n ){
        printf("-1\n");
        return 0;
    }


    REP(i,m)
        if( (!a[s[i].u] && a[s[i].v]) || (a[s[i].u] && !a[s[i].v]) )
            ans = min(ans,s[i].l);


    printf("%I64d\n", ans == 100000000000LL ? -1LL : ans );


    return 0;
}
