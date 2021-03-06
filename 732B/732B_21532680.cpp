/*************\
# Ahmed Dinar #
# CSE,JUST    #
\*************/

#include <bits/stdc++.h>

using namespace std;

#define FI           freopen("in.txt","r",stdin)
#define FO           freopen("out.txt","w",stdout)

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

#define oo           100000000000000LL
#define MAX          505

int a[MAX];


int main(){

   //FI;

    ios_base::sync_with_stdio(0); cin.tie(0);


    int k,n,ans = 0;
    cin>>n>>k;

    REP(i,n) cin>>a[i];

    for(int i=1; i<n; i++){
        if( a[i-1] + a[i] < k ){
            int p = k  - (a[i-1] + a[i]);
            ans += p;
            a[i] += p;
        }
    }


    cout << ans << endl;
    REP(i,n) cout << a[i] << " ";


    return 0;
}
