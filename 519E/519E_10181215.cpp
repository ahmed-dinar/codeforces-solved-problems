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

#define PI           2*acos(0.0)
#define EPS          1e-9
#define MAX          100002
#define oo           20000000000000LL
#define MOD          1000000007LL

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


vci g[MAX];
int depth[MAX],subt[MAX],par[MAX],P[MAX][25];

void dfs(int u,int p,int d){
    depth[u]=d;
    subt[u] = 1;
    par[u]=p;
    REP(i,g[u].sz){
        int v=g[u][i];
        if( v != p ){
            dfs(v,u,d+1);
            subt[u] += subt[v];
        }
    }
}

void preLca(int n){
    memset(&P,-1,sizeof(P));
    REP(i,n)
        P[i][0]=par[i];

    for(int j=1;(1<<j)<n; j++)
        for(int i=0; i<n; i++)
            if(P[i][j-1]!=-1)
                P[i][j]=P[P[i][j-1]][j-1];
}

int LCA(int n,int a,int b){

    if(depth[a]<depth[b])
        swap(a,b);

    int x=1;

    for(x = 1; (1 << x) <= depth[a]; x++);
    x--;

    for(int i=x; i>=0; i--)
        if(depth[a]-(1<<i)>=depth[b])
           a=P[a][i];

    if(a==b) return a;

    for(int i=x; i>=0; i--)
        if( P[a][i]!=-1 && P[a][i]!=P[b][i])
            a=P[a][i],b=P[b][i];

    return par[a];
}

int parent(int u,int k){

    for(int i=20; i>=0; i--){
        if( (1<<i)<=k && P[u][i]!=-1 ){
            u = P[u][i];
            k -= (1<<i);
        }
    }

    return u;
}

int go(int cur, int dd){
    for(int i = 20; i >= 0; i--){
        if(P[cur][i] == -1) continue;
        if((1<<i) > dd) continue;

        dd -= (1<<i);
        cur = P[cur][i];
    }
    return cur;
}


int main() {

  //  filein;

    int n,u,v,m;
    IO(n);
    REP(i,n-1){
        IO(u); IO(v);
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0,0,0);
    preLca(n);

    IO(m);
    while(m--){
        IO(u); IO(v);
        --u; --v;
        if( u == v) printf("%d\n",n);
        else{


            int lca = LCA(n,u,v);
            int dis = depth[u] + depth[v] - 2*depth[lca];
            int du = depth[u] - depth[lca];
            int dv = depth[v] - depth[lca];

          //  cout << u+1 << " " << v+1 << " lca " << lca+1 <<    " Depths = " <<  depth[u]  << " " <<  depth[v]  << " " <<  depth[lca] << " dis " << dis << endl;

        //    cout << u+1 << " " << v+1 << " lca= " << lca+1 << "  distance = " << dis << " du = " << du << "  dv= " << dv  << " -> ";

            if(dis&1) puts("0");
            else if(du == dv){

                int pu = parent(u,du-1);
                int pv = parent(v,dv-1);

              //  cout << pu+1  << " " << pv+1 <<  " ans = " ;

                int ans = n - subt[pu] - subt[pv];

                printf("%d\n",ans);
            }
            else{

                if(depth[u] < depth[v]) swap(u,v);

                int pu = parent(u,dis/2);
                int pv = parent(u,dis/2 - 1);

                int ans = subt[pu] - subt[pv];

             //   cout << u+1  << " 's pa " << pu+1 << " && ";
              //  cout << " pa " << pv+1 << "   ans = ";

                printf("%d\n",ans);

            }
        }
    }

    return 0;
}
