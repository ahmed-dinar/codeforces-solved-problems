#include<bits/stdc++.h>

using namespace std;

#define pf(x) printf("%d",x)
#define pfd(x,y) printf("%d %d",x,y)
#define pfl(x) printf("%ld",x)
#define nl printf("\n")
#define cs(x) printf("Case %d: ",x)
#define csn(x) printf("Case %d:\n",x)
#define all(x) x.begin(),x.end()
#define Find(x,n) find(all(x),n)
#define pi acos(-1.0)
#define i64 long long
#define pb(x) push_back(x)
#define mset(x,v) memset(x,v,sizeof(x))
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%ld",&n)
#define scd(n,m) scanf("%d %d",&n,&m)
#define scdl(n,m) scanf("%ld %ld",&n,&m)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("my.txt","w",stdout)
#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define inf 100
#define MAX 1000000000

template<class T>bool isEven(T a){ return (a%2==0);}
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>T Max(T n,T p) { return (n>=p) ? n : p; }
template<class T>T ABS(T n) { return (n<0) ?  (-n) :  n; }

int main(){

    // filein;

    int a;
    while( scanf("%d",&a) == 1){
        set<int>s;
        s.insert(a);
        int totl[20] = {0};
        totl[a]++;
        for(int i=0; i<5; i++){
            scanf("%d",&a);
            s.insert(a);
            totl[a]++;
        }
                bool alien=true;
                int mn=15;
                totl[mn]=inf;
                for(set<int>::iterator it=s.begin(); it!=s.end(); it++){
                    int x=*it;
                   // cout << x <<" " << totl[x] << endl;
                    if( totl[x]>=4 ){
                        alien=false;
                    }
                    if(totl[mn]>totl[x])
                        mn = x;
                }
                if( alien )
                    printf("Alien\n");
                else if( totl[mn]==1 )
                    printf("Bear\n");
                else
                    printf("Elephant\n");
    }
    return 0;
}


