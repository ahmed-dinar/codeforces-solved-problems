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

#define EPS 0.0000000001
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
#define MAX 65
#define inf 2000000000
#define MOD 100000000

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

int main()
{
    

    int n,x;
    cin>>n>>x;
    vector<pr>v;
    REP(i,n){
        int l,r;
        scanf("%d %d",&l,&r);
        v.pb( mp(l,r) );
    }
    sort( all(v) );
    int total=0;
    int cur=1;
    REP(i,v.size()){
        while( cur+x <=v[i].fi ){
            cur += x;
        }
        if(cur<v[i].fi){
             total += (v[i].ss-cur+1);
             cur = v[i].ss+1;
        }
        else if(cur==v[i].fi){
            total+= (v[i].ss-v[i].fi+1);
            cur = v[i].ss+1;
        }
    }
    cout << total << endl;
    return 0;
}
