#include<bits/stdc++.h>

using namespace std;

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
#define FOR(i,n) for(int i=0;i<n; i++)
#define inf 10000.0
#define MAX 5000000
#define MOD 1000000007

bool isUpper(char ch){ if( ch>='A' && ch<='Z' ) return true; return false; }
bool isLower(char ch){ if( ch>='a' && ch<='z') return true; return false;}
bool isLetter(char ch){ if( ch>='A' && ch<='Z' || ch>='a' && ch<='z') return true; return false; }
bool isDigit(char ch){ if( ch>='0' && ch<='9') return true; return false; }
char toLower(char ch){ if (isUpper(ch)) return (ch+32); return ch; }
char toUpper(char ch){ if (isLower(ch)) return (ch-32); return ch; }

template<class T>bool isEven(T a){ return (a%2==0);}
template<class T>T sq(T a){ return a*a; }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>T Max(T n,T p) { if(n>=p) return n; return p; }
template<class T>T ABS(T n) { if(n<0) return -n; return n; }


int main()
{
    int r,c;
    cin >> r >> c;
    int m[r+2][c+2];
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            cin >> m[i][j];

    int a[r+2][c+2];
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            a[i][j]=1;

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if( m[i][j] == 0 ){
                for(int k=1;k<=c;k++)
                    a[i][k]=0;
                for(int k=1;k<=r;k++)
                    a[k][j]=0;
            }
        }
    }
    bool yes = true;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if( m[i][j] == 1 ){
                bool isonecol=false;
                bool isonerow=false;
                for(int k=1;k<=c;k++){
                    if(a[i][k]==1)
                        isonecol = true;
                }
                for(int k=1;k<=r;k++){
                    if(a[k][j]==1)
                        isonerow = true;;
                }
                if(!isonecol && !isonerow){
                    yes = false;
                    break;
                }
            }
        }
        if(!yes) break;
    }
    if(yes){
        cout << "YES" << endl;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cout << a[i][j];
                if(j<c) cout << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}

