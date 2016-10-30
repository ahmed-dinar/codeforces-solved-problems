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

#define vanish       scanf("\n")
#define nl           puts("")
#define endl         '\n'
#define i64          long long
#define all(x)       x.begin(),x.end()

#define Iterate(s)   for(typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define FOR(i,k,n)   for(__typeof(n) i = (k); i <= (n); ++i)
#define For(i,k,n)   for(__typeof(n) i = (k); i < (n); ++i)
#define ROF(i,k,n)   for(__typeof(n) i = k; i >= n; i--)
#define REP(i,n)     for(__typeof(n) i = 0; i < (n); ++i)

#define MAX          2000005LL
#define oo           1000000001
#define MOD          1000000007

int f[MAX] = {};
i64 rub[MAX];
i64 primes[MAX];

bool palin(int x){
    int ret = 0,d=x;
    while(x){
        ret = ret*10 + x%10;
        x /= 10;
    }
    return (ret==d);
}

void sieve(){

    f[1] = f[0] = 1;
    for(int i=4; i<=MAX; i+=2)
        f[i] = 1;

    for(int i=3; i*i<=MAX; i+=2)
        if(f[i]==0)
            for(int j=i*i; j<=MAX; j+=2*i)
                f[j] = 1;

    rub[0] = 0LL;
    primes[0] = 0LL;
    for(int i=1; i<=MAX; i++){

        rub[i] = rub[i-1];
        if(palin(i))
            ++rub[i];

        primes[i] = primes[i-1];
        if(f[i]==0)
            ++primes[i];
    }
}

i64 res(i64 p, i64 q){
    for(int i=MAX; i>=1; i--){
        i64 u = p*rub[i];
        i64 v = q*primes[i];
        if(v<=u)
            return i;
    }
    return -1;
}

int main(){

    sieve();

    i64 p,q;
    cin>>p>>q;

    i64 ans = res(p,q);

    if(ans==-1) puts("Palindromic tree is better than splay tree");
    else cout << ans;

    return 0;
}













