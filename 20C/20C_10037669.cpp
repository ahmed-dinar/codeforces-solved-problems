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

#define all(x)       x.begin(),x.end()
#define nfound(v,n)  find(all(v),n) == v.end()
#define found(v,n)   find(all(v),n) != v.end()
#define UB(v,n)      upper_bound( all(v),n ) - v.begin()
#define LB(v,n)      lower_bound( all(v),n ) - v.begin()

#define on(n,p)      (n | (1<<(p)))
#define off(n,p)     (n & ~(1<<p)
#define check(n,p)   (bool)(n & (1<<(p)))

#define MS(x,v)      memset(&x,v,sizeof(x))
#define CL(x)        memset(&x,0,sizeof(x))
#define mp           make_pair
#define pb           push_back
#define sz           size()
#define cl           clear()
#define pp           pop()
#define em           empty()
#define ss           second
#define fi           first
#define sf           scanf
#define pf           printf

#define sc1(n)       sf("%d",&n)
#define sc2(n,m)     sf("%d %d",&n,&m)
#define sc3(n,m,v)   sf("%d %d %d",&n,&m,&v)
#define vanish       sf("\n")
#define nl           puts("")
#define show(x)      cout << #x << " = " << x

#define Iterate(s)   for(typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define FOR(i,k,n)   for(__typeof(n) i = (k); i <= (n); ++i)
#define For(i,k,n)   for(__typeof(n) i = (k); i < (n); ++i)
#define ROF(i,n)     for(__typeof(n) i = n; i >= 0; i--)
#define REP(i,n)     for(__typeof(n) i = 0; i < (n); ++i)

#define maxi(x,y)    ((x)>(y) ? (x) : (y))
#define mini(x,y)    ((x)<(y) ? (x) : (y))
#define ABS(x)       ((x)<0 ? (-(x)) : (x))

#define PI           acos(-1.0)
#define EPS          1e-9
#define MAX          100005
#define oo           20000000000000LL
#define MOD          1000000007

typedef long long i64;
typedef unsigned long long ui64;
typedef pair<int,int> pri;
typedef vector<int> vci;
typedef vector<string> vcs;
typedef vector<pri> vcp;

template<class T>inline void IO(T &x){
    char c=getchar();
    T sgn=1;
    while(c<'0'|| c>'9'){
        if(c=='-') sgn=-1;
        c=getchar();
    }
    x=0;
    while(c>='0'&&c<='9'){
        x=(T)(x<<1)+(x<<3)+c-'0';
        c=getchar();
    }
    x*=sgn;
}

template<class T>T bMod(T A,T P,T M){
    if(P==0) return (T)1;
    if(!(P&1)){
        T temp=bMod(A,P/2);
        return ((temp%M)*(temp%M))%M;
    }
    return ((A%M)*(bMod(A,P-1)%M))%M;
}

template<class T>T InMod(T A,T M){return bMod(A,M-2,M);}
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
template<class T>string toString(T n){ stringstream ss; string num; ss<<n; ss>>num; return num; }
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
bool iseq(double a,double b){return fabs(a-b)<EPS;}
template<class T>T todeg(T x) { return (180.0*x)/((T)PI);}
template<class T>T torad(T x) { return (x*(T)PI)/(180.0);}
template<class T>double _distance(T x1,T y1,T x2, T y2){return 1.0*sqrt(sq(x1-x2)+sq(y1-y2));}

//int kx[]={-2,-2,+2,+2,+1,-1,+1,-1};
//int ky[]={+1,-1,+1,-1,-2,-2,+2,+2};

//int dx[]={+0,+0,-1,+1,+1,+1,-1,-1};
//int dy[]={+1,-1,+0,+0,-1,+1,+1,-1};

//--------------------------END OF TEMPLATE---------------------------------------------------------------

struct edge
{
    int v;
    i64 uv;
    edge(int v,i64 uv) : v(v),uv(uv) {}
    bool operator<(const edge& kk)const{ return uv>kk.uv; }
};

vector<edge>g[MAX];
i64 d[MAX];
int par[MAX];

bool Dijkstra(int n){
    priority_queue<edge>q;
    q.push( edge(1,0) );
    d[1]=0;
    while(!q.em){
        int u=q.top().v; q.pp;
        REP(i,g[u].sz){
            int v=g[u][i].v;
            i64 uv=g[u][i].uv;
            if( d[v]>d[u]+uv ){
                par[v]=u;
                d[v] = d[u]+uv;
                q.push( edge(v,d[v]) );
            }
        }
    }
    return (d[n]!=oo);
}

void printPath(int u){
    if(u==1){
        printf("%d",u);
        return;
    }
    printPath(par[u]);
    printf(" %d",u);
}

int main(){

  //  filein;
   // fileout;


    int n,m,u,v;
    i64 uv;

    IO(n); IO(m);

    FOR(i,1,n) d[i]=oo;

    while(m--){
        IO(u); IO(v); IO(uv);
        g[u].pb( edge(v,uv) );
        g[v].pb( edge(u,uv) );
    }

    if(Dijkstra(n)) printPath(n);
    else printf("-1");
    nl;

    return 0;
}