#include<bits/stdc++.h>

using namespace std;

#define ll long long

int h[105];
int n;

int mx_mn(int *x,int *y)
{
    int mx=h[0],mn=h[0];
    *x=0;*y=0;
    for(int i=1; i<n; i++)
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
        int k;
        cin >> n >> k;
        int u,v;
        map<int,int>M;
        for(int i=0; i<n; i++){
            scanf("%d",&h[i]);
            M[h[i]]++;
        }
        map<int,map<int,int> >ans;
        vector<int>temp;
        int to=0,steps=0;
        while(mx_mn(&u,&v) == 0)
        {
            if(steps==k) break;
            h[u]--;
            h[v]++;
            ans[to][0]=u+1;
            ans[to++][1]=v+1;
            map<int,int>m;
            for(int i=0; i<n; i++){
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
            steps++;
        }
        cout << abs(h[u]-h[v]) << " " << steps  <<endl;
        for(int i=0; i<steps; i++) cout << ans[i][0] << " " << ans[i][1] << endl;
    return 0;
}
