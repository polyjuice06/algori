// dp[i][j] : i번째 기업까지 j만원 투자시 최대 이익
// dp[i][j] = dp[i-1][j-k] + profit[i][k]의 최대
#include <bits/stdc++.h>

using namespace std;
int n,k,dp[21][305],profit[21][305];

void solve(){
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            for(int p=0;p<=j;p++){
                dp[i][j] = max(dp[i][j],dp[i-1][j-p] + profit[i][p]);
            }
        }
    }
    /*for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }*/
    printf("%d\n",dp[k][n]);
}

void trace(int company,int invest){
    if(company == 0) return;
    for(int i=0;i<=n;i++){
        if(dp[company][invest] == dp[company-1][invest-i]+profit[company][i]){
            trace(company-1,invest-i);
            printf("%d ",i);
            break;
        }
    }
}

int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        int price;
        scanf("%d",&price);
        for(int j=1;j<=k;j++){
            scanf("%d",&profit[j][price]);
        }
    }
    solve();
    trace(k,n);
    return 0;
}
