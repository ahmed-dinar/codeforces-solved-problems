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

int v[202][202] = {};

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);




    int n;
    string s;
    cin>>n;
    cin>>s;


    int ans = 0;
    REP(i,s.size()){

        for(int j=0; j<i; j++){
            int x=0,y=0;
            for(int k=j; k<=i; k++){

                if( s[k] == 'U' ) y -= 1;
                else if( s[k] == 'D' ) y += 1;
                else if( s[k] == 'L' ) x -= 1;
                else if( s[k] == 'R' ) x += 1;

               //  cout << i << " " << j << " " << k << " -> " << x << " " << y << endl;

                if( x==0 && y==0 && v[j][k]==0 ){
                    ans++;
                    v[j][k] = 1;
                }


            }
           // nl;
        }
       // nl;
    }

    cout << ans << endl;


    return 0;
}
