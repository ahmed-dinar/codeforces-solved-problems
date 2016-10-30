#include<bits/stdc++.h>

using namespace std;

#define ll long long

int h[55];

int mx_mn(int *x,int *y)
{
    int mx=h[0],mn=h[0];
    *x=0;*y=0;
    for(int i=1; i<5; i++)
    {
        if(h[i]>mx){
            mx=h[i];
            *x=i;
        }
        if(h[i]<mn){
            mn=h[i];
            *y=i;
        }
    }
    if(mx != mn)
        return 0;
    return 1;
}

int main()
{

    int u,v,iszero=1;
    map<int,int>M;
    for(int i=0; i<5; i++){
        scanf("%d",&h[i]);
        M[h[i]]++;
        if(h[i]!=0) iszero = 0;
    }
    if(iszero == 1){
        cout << "-1";
    }
    else{
        vector<int>temp;
        while(mx_mn(&u,&v) == 0)
        {
            h[u]--;
            h[v]++;
            map<int,int>m;
            for(int i=0; i<5; i++){
                if(m[h[i]]==0){
                    temp.push_back(h[i]);
                }
                m[h[i]]++;
            }
            int sz=temp.size();
            bool is=false;
            for(int i=0; i<sz; i++){
                if(m[temp[i]]!=M[temp[i]]){
                    is=true;
                    break;
                }
            }
            M.clear();
            M.insert(m.begin(),m.end());
            if(!is) break;
            temp.clear();
        }
        if(temp.size() <=1) cout << h[0];
        else cout << "-1";
    }
    return 0;
}


