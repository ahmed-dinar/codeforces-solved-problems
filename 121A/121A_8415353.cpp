#include<bits/stdc++.h>

using namespace std;

#define all(x) (x.begin(),x.end())
#define Find(x,n) find(all(x),n)
#define pi acos(-1.0)
#define i64 long long
#define pb(x) push_back(x)
#define mset(x,v) memset(x,v,sizeof(x))
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%ld",&n)
#define scll(n) scanf("%lld",&n)
#define scd(n,m) scanf("%d %d",&n,&m)
#define scdl(n,m) scanf("%ld %ld",&n,&m)
#define scdll(n,m) scanf("%lld %lld",&n,&m)
#define file freopen("in.txt","r",stdin)

template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>T isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

vector<i64>lucky;

void gen_lucky(){
    lucky.pb(4);
    lucky.pb(7);
    int j=0;
    for(int i=0;i<9; i++){
        int sz=lucky.size();
        while(j<sz){
            i64 l = lucky[j];
            lucky.pb(l*10+4);
            lucky.pb(l*10+7);
            j++;
        }
    }
}



int main(){
    gen_lucky();
    int sz=2046;
    i64 l,r;
    while( scanf("%I64d %I64d",&l,&r) == 2 ){
        int index = (int)(lower_bound (lucky.begin(), lucky.end(), l)-lucky.begin());
        int index2 = (int)(lower_bound (lucky.begin(), lucky.end(), r)-lucky.begin());
        i64 res=0;
        i64 tem=l;
        for(int i=index; i<index2; i++){
            res += lucky[i]*(lucky[i]-tem+1);
            tem=lucky[i]+1;
        }
        res += lucky[index2]*(r-tem+1);
         cout << res << endl;
       
    }
    return 0;
}