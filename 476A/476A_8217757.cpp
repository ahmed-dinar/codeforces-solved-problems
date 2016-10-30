#include<bits/stdc++.h>

using namespace std;

int e[] = {2,1};
int n,m;
int taken[4];
bool is;
int res;

void isMul(int i,int j){
    if(is) return;
    if(j==n && !is){
        res = taken[2]+taken[1];
        if(res>=m &&res%m==0){
            is = true;
        }
        return;
    }
    if(i>=2){
        if(j==n){
            res = taken[2]+taken[1];
            if(res>=m && res%m==0){
                is = true;
            }
        }
        return;
    }

    if(j+e[i] <= n){
        taken[e[i]]++;
        isMul(i,j+e[i]);
        taken[e[i]]--;
    }
    isMul(i+1,j);
}

int main(){
    while(scanf("%d %d",&n,&m) == 2){
        memset(taken,0,sizeof(taken));
        is = false;
        isMul(0,0);
        if(is)
            printf("%d\n",res);
        else
            printf("-1\n");
    }
    return 0;
}
