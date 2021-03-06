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
#define oo           100000000000LL
#define MOD          1000000007

vector<pair<i64,i64> >p;

bool SO(pair<i64,i64> x, pair<i64,i64> y){
    if( x.fi == y.fi ) return x.ss > y.ss;
    else return x.fi < y.fi;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);



    int n;
    i64 d;

    cin>>n>>d;

    REP(i,n){
        i64 m,s;
        cin>>m>>s;
        p.pb( mp(m,s) );
    }

    p.pb( mp(100000000000LL,0LL) );

    sort(all(p),SO);



    i64 ans = 0LL, t=0LL,temp=0;
    REP(i,n){
        t+=p[i].ss;
        while( temp<n && abs(p[i].fi - p[temp].fi) >= d ){
            t -= p[temp].ss;
            temp++;
        }
        ans = max(ans,t);
    }

    cout << ans << endl;

    return 0;
}

















