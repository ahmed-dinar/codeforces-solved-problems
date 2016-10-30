#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll GetGCDByModulus(ll value1, ll value2)
{
    while (value1 != 0 && value2 != 0)
    {
        if (value1 > value2)
            value1 %= value2;
        else
            value2 %= value1;
    }
    return max(value1, value2);
}

bool coPrime(ll value1, ll value2)
{
    return GetGCDByModulus(value1, value2) == 1;
}

int main(){

    ll l,r;
    cin >> l >> r;
    bool br=false;
    for(ll i=l; i<=r; i++){
       for(ll j=i+1; j<=r; j++){
            for(ll k=j+1; k<=r; k++){
                if(!coPrime(i,k)){
                    if(coPrime(i,j) && coPrime(j,k)){
                        cout << i << " " << j << " " << k << endl;
                        br = true;
                        break;
                    }
                }
            }
            if(br) break;
       }
       if(br) break;
    }
    if(!br) cout << "-1" << endl;
    return 0;
}
