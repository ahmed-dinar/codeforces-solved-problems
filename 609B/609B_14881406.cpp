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
#define fileout      freopen("out2.txt","w",stdout)

#define MS(x,v)      memset(&x,v,sizeof(x))
#define CL(x)        memset(&x,0,sizeof(x))
#define mp           make_pair
#define pb           push_back
#define sz           size()
#define cl           clear()
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
#define sq(x)        (x*x)

#define EPS          0.0000001
#define MAX          300003
#define oo           1000000000000000LL
#define MOD          1000000007

#define PI           acos(-1.0)

i64 p[12];

int main(){

     ios_base::sync_with_stdio(0); cin.tie(0);

    //filein;
    //fileout;

    int n,m,x;
    cin>>n;
    cin>>m;

    CL(p);

    REP(i,n) {
        cin>>x;
        p[x]++;
    }

    i64 ans = 0;
    for(int i=1; i<=m; i++){
        if(p[i]){
            //cout << i << " " << p[i] << " " << n-p[i] << endl;

            for(int j=i+1; j<=m; j++){
                ans += p[j]*p[i];
            }


        }
    }

    cout << ans << endl;

    return 0;
}

