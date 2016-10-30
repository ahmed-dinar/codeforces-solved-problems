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

using namespace std;

#define filein freopen("in.txt","r",stdin)
#define fileout freopen("out.txt","w",stdout)

#define cs(x) printf("Case %d: ",x)
#define csn(x) printf("Case %d:\n",x)

#define nFind(v,n) find(all(v),n)==v.end()
#define Find(v,n) find(all(v),n)!=v.end()
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define sz size()
#define cl clear()
#define em empty()
#define ss second
#define fi first

#define sc(n) scanf("%d",&n)
#define nl puts("")

#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define For(i,k,n) for(int i=k;i<n; i++)

#define EPS 1e-9
#define pi acos(-1.0)
#define MAX 6
#define oo 2000000000.0
#define MOD 1000000007

typedef long long i64;
typedef pair<int,int> pri;
typedef vector<string> vcs;
typedef vector<int> vci;
typedef vector<pri> vcp;

template<class T>bool iseq(T a,T b){return fabs(a-b)<EPS;}
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }


int main(){



    vcs u;
    map<string,vcs >user;
    map<string,int>vis;
    int n;
    cin>>n;
    REP(i,n){
        string old,ne;
        cin>>old>>ne;
        user[old].pb(ne);
        u.pb(old);
    }
    vector<pair<string,string> >res;
    REP(i,u.sz){
        string v=u[i];
        if(vis[v]) continue;
        string w=v;
        vis[v]=1;
        while(user[w].sz){
            w=user[w][0];
            vis[w]=1;
        }
        res.pb(mp(v,w));
    }
    int ans=res.sz;
    cout << ans << endl;
    REP(i,ans)
        cout << res[i].fi << " " << res[i].ss << endl;

    return 0;
}
