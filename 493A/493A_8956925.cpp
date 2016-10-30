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

#define fr first
#define ss second
#define pf printf
#define pi acos(-1.0)
#define i64 long long
#define nl printf("\n")
#define pb(x) push_back(x)
#define cs(x) printf("Case %d: ",x)
#define csn(x) printf("Case %d:\n",x)
#define all(x) x.begin(),x.end()
#define Find(x,n) find(all(x),n)
#define mset(x,v) memset(x,v,sizeof(x))
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%ld",&n)
#define scd(n,m) scanf("%d %d",&n,&m)
#define scdl(n,m) scanf("%ld %ld",&n,&m)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("my.txt","w",stdout)
#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define fr(i,k,n) for(int i=k;i<n; i++)
#define MAX 100005
#define inf 2000000

template<class T>bool isEven(T a){ return (a%2==0);}
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>T Max(T n,T p) { return (n>=p) ? n : p; }
template<class T>T Min(T n,T p) { return (n>=p) ? p : n; }

int a[MAX];
int tree[MAX*3];

void segTree(int n,int l,int h){
    if(l==h){
        tree[n]=1;
        return;
    }
    int md=(l+h)/2;
    segTree(n*2,l,md);
    segTree(n*2+1,md+1,h);
}

int main()
{
    

    int n;
    string hm,aw;
    map<int,map<char,pair<int,char> > >rec;
    map<char,string>name;
    cin >> hm >> aw;
    name['h'] = hm;
    name['a'] = aw;
    sc(n);
    while(n--){
        int t,m;
        char ch,c;
        scanf("%d %c %d %c",&t,&ch,&m,&c);
        if( c == 'r' && rec[m][ch].first!=1000 ){
            pf("%s %d %d\n",name[ch].c_str(),m,t);
            rec[m][ch].first = 1000;
        }
        else if( c == 'y' && ( rec[m][ch].first!=1000 && rec[m][ch].first!=0 ) ){
            pf("%s %d %d\n",name[ch].c_str(),m,t);
            rec[m][ch].first = 1000;
        }
        else if( c == 'y' &&  rec[m][ch].first==0  ){
            rec[m][ch].first = t;
            rec[m][ch].second = c;
        }
    }
    return 0;
}
