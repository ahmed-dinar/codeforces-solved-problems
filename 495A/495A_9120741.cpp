#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
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

#define mp make_pair
#define pi acos(-1.0)
#define i64 long long
#define nl printf("\n")
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define Find(x,n) find(all(x),n)
#define mset(x,v) memset(x,v,sizeof(x))
#define sc(n) scanf("%d",&n)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("my.txt","w",stdout)
#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define fr(i,k,n) for(int i=k;i<n; i++)
#define MAX 200005
#define inf 2000000000

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

int pos(int n){
    if(n==0) return 2;
    if(n==1) return 7;
    if(n==2) return 2;
    if(n==3) return 3;
    if(n==4) return 3;
    if(n==5) return 4;
    if(n==6) return 2;
    if(n==7) return 5;
    if(n==8) return 1;
    if(n==9) return 2;
}

int main()
{
  

    string s;
    cin>>s;
    if(s.size()==1){
        int n=s[0]-'0';
        printf("%d\n",pos(n));
    }
    else{
        int m=s[0]-'0';
        int n=s[1]-'0';
        int a=pos(m);
        int b=pos(n);
        printf("%d\n",a*b);
    }
    return 0;
}