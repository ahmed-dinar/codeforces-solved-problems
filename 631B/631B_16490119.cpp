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
#define MAX          5005


map<int,pair<int,int> >r;
map<int,pair<int,int> >c;


int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);


    int n,m,k;
    cin>>n>>m>>k;


    REP(i,k){
        int t,d,color;
        cin>>t>>d>>color;
        if( t==1 ) r[d].fi = i,r[d].ss = color;
        else if( t==2 ) c[d].fi = i,c[d].ss = color;
    }

    FOR(i,1,n){
        FOR(j,1,m){
            if( r[i].ss == 0 && c[j].ss == 0 ) cout << "0 ";
            else if( r[i].ss == 0 && c[j].ss != 0 ) cout << c[j].ss << " ";
            else if( r[i].ss != 0 && c[j].ss == 0 ) cout << r[i].ss << " ";
            else{
                if( r[i].fi > c[j].fi ) cout << r[i].ss << " ";
                else cout << c[j].ss << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
