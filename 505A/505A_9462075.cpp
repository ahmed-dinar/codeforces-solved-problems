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
#define scd(n,m) scanf("%d %d",&n,&m)
#define sct(n,m,v) scanf("%d %d %d",&n,&m,&v)
#define nl puts("")

#define REP(i,n) for(__typeof(n) i = 0; i < (n); ++i)
#define FOR(i,k,n) for(__typeof(n) i = (k); i <= (n); ++i)
#define For(i,k,n) for(__typeof(n) i = (k); i < (n); ++i)

#define EPS 1e-7
#define pi acos(-1.0)
#define MAX 15
#define oo 20000000
#define MOD 1000000007

typedef long long i64;
typedef pair<int,int> pri;
typedef vector<int> vci;
typedef vector<i64> vci64;
typedef vector<pri> vcp;

template<class T>bool iseq(T a,T b){return fabs(a-b)<EPS;}
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

int palindrome(string s,int k,int l){
    while(k<l){
        if(s[k]!=s[l]) return 0;
        k++; l--;
    }
    return 1;
}

int main(){

 

    string s;
    cin>>s;
    int a=0;
    int b=s.sz-1;
    int ln=s.sz;
    if( palindrome(s,0,b) ){
        int m=ln/2;
        s.insert(m,1,s[m]);
        if( palindrome(s,0,ln) ) cout << s << endl;
        else puts("NA");
    }
    else if(s[a]==s[b]){
        int pos=0;
        while(a<b){
            if(s[a]!=s[b]){
                string p=s;
                string q=s;
                string r=s;
                string t=s;
                p.insert(a,1,s[b]);
                r.insert(a+1,1,s[b]);
                q.insert(b,1,s[a]);
                t.insert(b+1,1,s[a]);
                if( palindrome(p,0,ln) ) puts(p.c_str());
                else if( palindrome(q,0,ln) ) puts(q.c_str());
                else if( palindrome(r,0,ln) ) puts(r.c_str());
                else if(  palindrome(t,0,ln) ) puts(t.c_str());
                else puts("NA");
                break;
            }
            a++; b--;
        }
    }
    else{
        string p=s;
        string q=s;
        string r=s;
        string t=s;
        p.insert(a,1,s[b]);
        r.insert(a+1,1,s[b]);
        q.insert(b,1,s[a]);
        t.insert(b+1,1,s[a]);

        if( palindrome(p,0,ln) ) puts(p.c_str());
        else if( palindrome(q,0,ln) ) puts(q.c_str());
        else if( palindrome(r,0,ln) ) puts(r.c_str());
        else if(  palindrome(t,0,ln) ) puts(t.c_str());
        else puts("NA");

    }
    return 0;
}
