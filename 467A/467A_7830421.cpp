#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int total = 0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        int p,q;
        scanf("%d %d",&p,&q);
        if( (q-p)>=2 ) total++;
    }
    printf("%d",total);
    return 0;
}
