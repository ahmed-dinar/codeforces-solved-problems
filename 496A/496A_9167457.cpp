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

#define eps 0.0000000001
#define pr pair<int,int>
#define mp make_pair
#define ss second
#define fi first
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
#define MAX 2005
#define inf 2000000000
#define MOD 100000000

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

int main()
{
    //filein;

    int n;
    cin >> n;
    int a[n+1];
    REP(i,n) cin>>a[i];
    if(n==1)
        cout << a[0] << endl;
    else if(n==2)
        cout << a[1]-a[0] << endl;
    else if(n==3){
        cout << a[2]-a[0] << endl;
    }
    else{
        int res = inf;
        for(int i=1;i<n-1;i++){
           int r = 0;
           for(int j=0;j<n-1; j++){
                if(j==i && j-1>=0) r = max(r,a[j+1]-a[j-1]);
                else if(j+1==i && j+2<n) r = max(r,a[j+2]-a[j]);
                else r = max(r,a[j+1]-a[j]);
           }
           res = min(res,r);
        }
        cout <<  res << endl;
    }
    return 0;
}

