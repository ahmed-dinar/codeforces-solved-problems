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
#define MAX          100005

stack<char>q;

bool match(char a,char b){
    return (a=='{' && b=='}') || (a=='}' && b=='{')
           || (a=='[' && b==']') || (a==']' && b=='[')
           || (a==')' && b=='(') || (a=='(' && b==')')
           || (a=='<' && b=='>') || (a=='>' && b=='<');
}

int main(){

     ios_base::sync_with_stdio(0); cin.tie(0);

    //FI;
    //FO;


    string s;
    cin>>s;

    int ans = 0;
    REP(i,s.size()){
        if( s[i] == '<' || s[i] == '{' || s[i] == '(' || s[i] == '[' ){
            q.push(s[i]);
        }
        else if( !q.size() ){
            cout << "Impossible" << endl;
            return 0;
        }
        else{
            char ch = q.top(); q.pop();
            if( !match(ch,s[i]) ){
                //cout << ch << " " << s[i] << endl;
                ans++;
            }
        }
    }

     if( q.size() ){
        cout << "Impossible" << endl;
        return 0;
    }

    cout << ans << endl;

    return 0;
}
