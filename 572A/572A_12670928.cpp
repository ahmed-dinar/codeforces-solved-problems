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

#define MAX          100005
#define oo           1000000001
#define MOD          1000000007



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int x,y = -1,na,nb,n,k,m;
    cin>>na>>nb;
    cin>>k>>m;

    FOR(i,1,na){
        cin>>n;
        if(i==k) x = n;
    }

    FOR(i,1,nb){
        cin>>n;
        if( n>x && y==-1 ) y = i;
    }

   // cout << nb << "  " << y << " " << nb - y << endl;

    if( y!=-1 && (nb - y + 1) >= m ) puts("YES");
    else puts("NO");

    return 0;
}

















