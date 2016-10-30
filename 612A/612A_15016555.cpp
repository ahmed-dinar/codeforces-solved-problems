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


int main(){

     ios_base::sync_with_stdio(0); cin.tie(0);

    //FI;
    //FO;

    int n,p,q;
    string s;
    cin>>n>>p>>q;
    cin>>s;

    if( p+q == n ){
        cout << "2" << endl;
        REP(i,p) cout << s[i];
        cout << endl;
        FOR(i,n-q,n-1) cout << s[i];
    }
    else if( p<=n && n%p == 0 ){
        cout << n/p << endl;
        int x = 0;
        REP(i,n){
            cout << s[i];
            if( x+1==p ) cout << endl,x=0;
            else x++;
        }
    }
    else if( q<=n && n%q == 0 ){
        cout << n/q << endl;
        int x = 0;
        REP(i,n){
            cout << s[i];
            if( x+1==q ) cout << endl,x=0;
            else x++;
        }
    }
    else if( p>n || q>n || p+q>n ){
        cout << "-1";
        return 0;
    }
    else{
        int j;
        for(j=p; j<=n; j+=p){
            if( (n-j)%q == 0 ) break;
            //cout << j << " " <<  n-j << endl;
        }

        if( j>=n ){
            cout << "-1";
            return 0;
        }

        cout << (j/p + (n-j)/q) << endl;

        int x = 0;
        REP(i,j){
            cout << s[i];
            if( x+1==p ) cout << endl,x=0;
            else x++;
        }

        x = 0;
        FOR(i,j,n-1){
            cout << s[i];
            if( x+1==q ) cout << endl,x=0;
            else x++;
        }


    }



    return 0;
}
