#include <iostream>
using namespace std;
const int INF=1e18;
int n;
int dist[101],check[101];
int A[101][101];
int Prim(){
    int i, j, minNode, minValue, ans = 0;
    for(i=2;i<=n;++i) dist[i] = INF;
    for(i=1;i<=n;++i){
        minValue = INF; /// extract min
        for(j=1;j<=n;++j) if(check[j]==0 && minValue > dist[j]){
            minNode = j, minValue = dist[j];
        }
        /// check min node
        ans += minValue, check[minNode] = 1;
        /// relaxation
        for(j=1;j<=n;++j) if(dist[j] > A[minNode][j]){
        dist[j] = A[minNode][j];
        }
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&A[i][j]);
        }
    }
    printf("%d",Prim());
    return 0;
}
