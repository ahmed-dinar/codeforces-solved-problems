#include<bits/stdc++.h>

using namespace std;

#define MAX 1000001

int bol[MAX]={0};
int prime[78500];

void sieve(){
    int sq=sqrt(MAX);
    bol[0]=1; bol[1]=0;
    for(int i=3; i<=sq; i+=2) if(bol[i]==0) for(int j=i*i; j<MAX; j += 2*i) bol[j]=1;

    for(int i=4; i<MAX; i+=2) bol[i] = 1;
}

int main(){

    sieve();

    int n;
    int k = 4;
    scanf("%d",&n);
    while(bol[n-k] == 0 || bol[k] == 0){
        k++;
    }
    printf("%d %d\n",k,n-k);
    return 0;
}





