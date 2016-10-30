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

#define MAX          105
#define oo           1000000001
#define MOD          1000000007

int a[MAX] = {};

int main(){

    int n,m;
    cin>>n>>m;

    REP(i,m){
        int x = -1,p;
        REP(j,n){
            int y;
            cin>>y;
            if( y>x ){
                x = y;
                p = j;
            }
        }
        a[p]++;
    }

    m = -1;
    int ans = 0;
    REP(i,n){
        if( a[i]>m ){
            m = a[i];
            ans = i;
        }
    }

    cout << ans+1 << endl;

    return 0;
}













