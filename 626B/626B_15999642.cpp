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

#define oo           100000000000000LL
#define MAX          200005

int ans[5] = {};
int dp[205][205][205] = {};

int solve(int r,int g,int b){

    //cout << r << " " << g << " " << b << endl;


    if( dp[r][g][b] ) return 0;

    dp[r][g][b] = 1;

    if( r+g+b == 0 ) return 0;

    if( g+b == 0 && r ) return 1;
    if( r+b == 0 && g ) return 2;
    if( r+g == 0 && b ) return 3;

    if( r+g+b==2 ){
        if( r==0 ) return 1;
        if( g==0 ) return 2;
        if( b==0 ) return 3;
    }

    if(r>0 && g>0)
        ans[solve(r-1,g-1,b+1)]++;

    if(r>0 && b>0)
        ans[solve(r-1,g+1,b-1)]++;

    if(g>0 && b>0)
        ans[solve(r+1,g-1,b-1)]++;

    if( r>1 ) ans[solve(r-1,g,b)]++;
    if( g>1 ) ans[solve(r,g-1,b)]++;
    if( b>1 ) ans[solve(r,g,b-1)]++;

    return 0;
}

int main(){

    //ios_base::sync_with_stdio(0); cin.tie(0);


    int n,r=0,g=0,b=0;
    string s;
    cin>>n;
    cin>>s;


    REP(i,s.size()){
        r += (s[i]=='R');
        g += (s[i]=='G');
        b += (s[i]=='B');
    }

   // cout << r << " " << g << " " << b << endl;

    ans[solve(r,g,b)]++;

    if( ans[3] ) cout << "B";
    if( ans[2] ) cout << "G";
    if( ans[1] ) cout << "R";

   // cout << ans[1] << " " << ans[2] << " " << ans[3] << endl;


    return 0;
}
