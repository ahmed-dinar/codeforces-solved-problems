//--------------//
//  Ahmed Dinar //
//  CSE, JUST   //
//--------------//
#include<bits/stdc++.h>

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
#define fr           front()
#define tp           top()
#define ss           second
#define fi           first

#define vanish       scanf("\n")
#define nl           puts("")
#define show(x)      cout << #x << " = " << x

#define Iterate(s)   for(typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define FOR(i,k,n)   for(__typeof(n) i = (k); i <= (n); ++i)
#define For(i,k,n)   for(__typeof(n) i = (k); i < (n); ++i)
#define ROF(i,k,n)   for(__typeof(n) i = k; i >= n; i--)
#define REP(i,n)     for(__typeof(n) i = 0; i < (n); ++i)

#define maxi(x,y)    ((x)>(y) ? (x) : (y))
#define mini(x,y)    ((x)<(y) ? (x) : (y))
#define ABS(x)       ((x)<0 ? (-(x)) : (x))

#define PI           acos(-1.0)
#define EPS          1e-9

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

#define MAX          1000000000
#define oo           100000000000000LL
#define MOD          1000000007

set<string>res;

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    cin>>s;
    int N = s.sz+1;
    string ans = "";

    for(char ch='a'; ch<='z'; ch++){
        string p = "";
        p+=ch;
        p.append(s);
        res.insert(p);
    }

    for(char ch='a'; ch<='z'; ch++){
        string p = s;
        p+=ch;
        res.insert(p);
    }

    REP(i,s.sz-1){
        string p = "",q="";

        FOR(j,0,i) p+=s[j];
        For(j,i+1,s.sz) q+=s[j];



        for(char ch='a'; ch<='z'; ch++){
            string t = p;
            t+=ch;
            t.append(q);
            res.insert(t);
        }
    }

    cout << res.sz << endl;



    return 0;
}
