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
#define ROF(i,n)     for(__typeof(n) i = n; i >= 0; i--)
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

#define MAX          505
#define oo           100000000000000LL
#define MOD          1000000007

int a[600][600],sum[600],res[600];

int main(){



    int n,m,q,r,c;

    scanf("%d %d %d",&n,&m,&q);

    FOR(i,1,n){
        sum[0] = 0;
        res[i] = 0;
        FOR(j,1,m){
            scanf("%d",&a[i][j]);

            if( a[i][j] == 0 ) sum[j] = 0;
            else  sum[j] = sum[j-1] + a[i][j];

            res[i] = max(res[i],sum[j]);
        }
    }

    while(q--){

        scanf("%d %d",&r,&c);

        if( a[r][c] == 0 )
            a[r][c] = 1;
        else
            a[r][c] = 0;

        int ans = 0;

        res[r] = 0;
        sum[0] = 0;



        FOR(i,1,m){

            if( a[r][i] == 0 )
                sum[i] = 0;
            else
                sum[i] = sum[i-1] + a[r][i];

            res[r] = max(res[r],sum[i]);
        }

        FOR(i,1,n) ans = max(ans,res[i]);

        printf("%d\n",ans);


    }

    return 0;
}
