#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int res  = max( (a+b+c),(a*b*c) );
    res = max(res,(a+b*c));
    res = max(res,(a+(b*c)));
    res = max(res,((a+b)*c));
    res = max(res,(a*b+c));
    res = max(res,(a*(b+c)));
    res = max(res,((a*b)+c));
    cout << res;
    return 0;
}
