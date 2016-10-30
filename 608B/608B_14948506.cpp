/*************\
# Ahmed Dinar #
# CSE,JUST    #
\*************/

#include <bits/stdc++.h>

using namespace std;

#define FI           freopen("in.txt","r",stdin)
#define FO           freopen("out2.txt","w",stdout)

#define MS(x,v)      memset(&x,v,sizeof(x))
#define CL(x)        memset(&x,0,sizeof(x))
#define mp           make_pair
#define pb           push_back
#define ss           second
#define fi           first

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
#define sq(x)        ((x)*(x))

#define PI           acos(-1.0)
#define EPS          0.0000001
#define MOD          1000000007

#define oo           1e9+1
#define MAX          200005

i64 x[MAX] = {};

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

   // FI;
    //FO;

    string a,b;
    cin>>a>>b;

    x[0] = b[0] - '0';

    FOR(i,1,b.size()-1) x[i] = x[i-1] + (b[i] - '0');

    i64 ans = 0LL,lna = (i64)a.size(), lnb = (i64)b.size();

    REP(i,a.size()){

        i64 p = lnb - lna + (i64)i;

        i64 sum;

        if( i==0 )  sum = x[p];
        else  sum = x[p] - x[i-1];

        if( a[i] == '0' ) ans += sum;
        else ans += p - (i64)i - sum + 1LL;

       // cout << i << " to " <<  p << " " << sum  << " " << p-i+1 <<  endl;
    }

    cout << ans << endl;

    return 0;
}

