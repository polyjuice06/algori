#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    int n;
    long long ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        pq.push(a);
    }
    while(pq.size()!=1){
        int b,c;
        b=pq.top();
        pq.pop();
        c=pq.top();
        pq.pop();
        pq.push(b+c);
        ans+=b+c;
    }
    printf("%lld",ans);
    return 0;
}
