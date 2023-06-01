#include <bits/stdc++.h>

using namespace std;
int visited[20001];
struct number{
    int mod;
    int leng;
    string s;
};

int main()
{
    int t;
    scanf("%d",&t);
    while(t>0){
        int n;
        memset(visited,0,sizeof(visited));
        queue<number> q;
        scanf("%d",&n);
        if(n == 1) {
            printf("1");
            printf("\n");
            t--;
            continue;
        }
        number x;
        x.mod = 1;
        x.leng = 1;
        x.s = '1';
        q.push(x);
        while(!q.empty()){
            number x1 = q.front();
            q.pop();
            number nextnum1, nextnum2;
            if(visited[x1.mod] == 1){
                continue;
            }
            visited[x1.mod] = 1;
            if(x1.leng > 100){
                cout<<"BRAK"<<'\n';
                t--;
                break;
            }
            else if(x1.mod%n==0){
                cout<<x1.s<<'\n';
                t--;
                break;
            }
            nextnum1.mod = (x1.mod*10)%n;
            nextnum1.s = x1.s + '0';
            nextnum1.leng = x1.leng + 1;
            nextnum2.mod = (x1.mod*10 + 1)%n;
            nextnum2.s = x1.s + '1';
            nextnum2.leng  = x1.leng + 1;
            q.push(nextnum2);
            q.push(nextnum1);
        }
    }
    return 0;
}
