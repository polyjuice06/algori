#include <iostream>
#include <queue>
using namespace std;
int m,n,k;
int sx,sy,fx,fy;
int bus[5001][5];
int buscross[5001][5001]={0,};
int usebus[5001]={0,};
struct bu{
    int num;
    int time;
};
queue<bu> q;
void bfs(){
    while(!q.empty()){
        bu out;
        bu in;
        out=q.front();
        if(bus[out.num][1]<=fx&&bus[out.num][3]>=fx&&bus[out.num][2]<=fy&&bus[out.num][4]>=fy){
            printf("%d",out.time);
            return;
        }
        q.pop();
        for(int i=1;i<=k;i++){
            if(buscross[out.num][i]==0) continue;
            if(usebus[i]==1) continue;
            usebus[i]=1;
            in.num=i;
            in.time=out.time+1;
            if(bus[i][1]<=fx&&bus[i][3]>=fx&&bus[i][2]<=fy&&bus[i][4]>=fy){
                printf("%d",in.time);
                return;
            }
            q.push(in);
        }
    }
}
void meet(){
    for(int i=1;i<k;i++){
        for(int j=i+1;j<=k;j++){
                if(bus[i][1]>bus[j][3]){
                    buscross[bus[i][0]][bus[j][0]]=0;
                    buscross[bus[i][0]][bus[j][0]]=0;
                }
                else if(bus[i][3]<bus[j][1]){
                    buscross[bus[i][0]][bus[j][0]]=0;
                    buscross[bus[j][0]][bus[i][0]]=0;
                }
                else if(bus[i][2]>bus[j][4]){
                    buscross[bus[i][0]][bus[j][0]]=0;
                    buscross[bus[j][0]][bus[i][0]]=0;
                }
                else if(bus[i][4]<bus[j][2]){
                    buscross[bus[i][0]][bus[j][0]]=0;
                    buscross[bus[j][0]][bus[i][0]]=0;
                }
                else{
                    buscross[bus[i][0]][bus[j][0]]=1;
                    buscross[bus[j][0]][bus[i][0]]=1;
                }
        }
    }
}
int main()
{
    scanf("%d %d",&m,&n);
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        int t;
        scanf("%d %d %d %d %d",&bus[i][0],&bus[i][1],&bus[i][2],&bus[i][3],&bus[i][4]);
        if(bus[i][1]>bus[i][3]){
            t=bus[i][1];
            bus[i][1]=bus[i][3];
            bus[i][3]=t;
        }
        else if(bus[i][2]>bus[i][4]){
            t=bus[i][2];
            bus[i][2]=bus[i][4];
            bus[i][4]=t;
        }
    }
    scanf("%d %d %d %d",&sx,&sy,&fx,&fy);
    meet();
    for(int i=1;i<=k;i++){
        if(bus[i][1]<=sx&&bus[i][3]>=sx&&bus[i][2]<=sy&&bus[i][4]>=sy){
            usebus[bus[i][0]]=1;
            bu b;
            b.time=1;
            b.num=bus[i][0];
            q.push(b);
        }
    }
    bfs();
    return 0;
}
