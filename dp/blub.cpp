// dp[s][e] : s번째 전구부터 e번째 전구까지 최소로 바꾸어야 하는 횟수
// dp[s][e] = min(dp[s][k] + dp[k][e] + (bulb[s]!=bulb[e])) (s<=k<=e)
// dp[i][i] = 0
#include <bits/stdc++.h>

using namespace std;
int n,k,bulb[205];
int dp[205][205];

int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&bulb[i]);
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n-i+1;j++){
            int s = j, e = i+j;
            int temp = 987654321;
            for(int k = s; k < e; k++){
                temp = min(temp, dp[s][k] + dp[k+1][e] + (int)(bulb[s]!=bulb[e]));
            }
            dp[s][e] = temp;
        }
    }
    printf("%d",dp[1][n]);
    return 0;
}
