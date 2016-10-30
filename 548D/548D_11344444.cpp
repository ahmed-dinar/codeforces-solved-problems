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

#define vanish       scanf("\n")
#define nl           puts("")
#define show(x)      cout << #x << " = " << x

#define Iterate(s)   for(typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define FOR(i,k,n)   for(__typeof(n) i = (k); i <= (n); ++i)
#define For(i,k,n)   for(__typeof(n) i = (k); i < (n); ++i)
#define ROF(i,k,n)     for(__typeof(n) i = k; i >= n; i--)
#define REP(i,n)     for(__typeof(n) i = 0; i < (n); ++i)

#define maxi(x,y)    ((x)>(y) ? (x) : (y))
#define mini(x,y)    ((x)<(y) ? (x) : (y))
#define ABS(x)       ((x)<0 ? (-(x)) : (x))

#define PI           acos(-1.0)
#define EPS          1e-9

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

void IOI(int &x){
    char c=getchar();
    while(c<'0'|| c>'9') c=getchar();

    x=0;
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar();
    }
}

template<class T>T Pow(T  b,T  p){
    T ret = 1;
    while(p>0){
        if(p&1) ret *= b ;
        p >>= (1ll) , b *= b ;
    }
    return ret;
}

template<class T>T bMod(T A,T P,T M){
    if(P==0) return (T)1;
    if(!(P&1)){
        T temp=bMod(A,P/2,M);
        return ((temp%M)*(temp%M))%M;
    }
    return ((A%M)*(bMod(A,P-1,M)%M))%M;
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

typedef long long i64;
typedef unsigned long long ui64;
typedef pair<int,int> pri;
typedef vector<int> vci;
typedef vector<string> vcs;
typedef vector<pri> vcp;

#define MAX          200005
#define oo           1000000001
#define MOD          1000000007

int a[MAX];
int lef[MAX],r[MAX];
int tree[MAX*4];
vci ans;
int N;
int vis[MAX] = {};

void make_tree(int node,int low,int high){
    if( low==high ){
        tree[node] = -1;
        return;
    }
    int md = (low+high)>>1;
    int le = node<<1;
    int ri = le+1;
    tree[le] = -1;
    tree[ri] = -1;
    make_tree(le,low,md);
    make_tree(ri,md+1,high);
}

void update(int node,int low,int high,int i,int j,int v){
    if( i>high || j<low) return;
    else if( low>=i && high<=j ){
        tree[node] = maxi(tree[node],v);
        return;
    }
    int md = (low+high)>>1;
    int le = node<<1;
    int ri = le+1;
    if( tree[node] != -1 ){
        tree[le] = maxi(tree[le],tree[node]);
        tree[ri] = maxi(tree[ri],tree[node]);
        tree[node] = -1;
    }
    update(le,low,md,i,j,v);
    update(ri,md+1,high,i,j,v);
}

void gen_res(int node,int low,int high){
    if( low == high ){
       printf("%d ",tree[node]);
       return;
    }
    int md = (low+high)>>1;
    int le = node<<1;
    int ri = le+1;
    if( tree[node] != -1 ){
        tree[le] = maxi(tree[le],tree[node]);
        tree[ri] = maxi(tree[ri],tree[node]);
        tree[node] = -1;
    }
    gen_res(le,low,md);
    gen_res(ri,md+1,high);
}

int main(){

 
    IOI(N);

    FOR(i,1,N) IOI(a[i]);

    a[0] = a[N+1] = 0;

    FOR(i,1,N){
        lef[i] = i-1;
        while( a[i]<=a[lef[i]] ) lef[i] = lef[lef[i]];
    }

    ROF(i,N,1){
        r[i] = i+1;
        while( a[i]<=a[r[i]] ) r[i] = r[r[i]];
    }

    //FOR(i,1,N) cout << lef[i] << " " << r[i] << endl;

    FOR(i,1,N)
        update(1,1,N,1,r[i] - lef[i] - 1,a[i]);

    gen_res(1,1,N);


    return 0;
}
