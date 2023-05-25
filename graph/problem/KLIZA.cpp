#include <bits/stdc++.h>

using namespace std;
int board[3][3];
char alphabet[9] = {'1','2','3','4','5','6','7','8','X'};
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};
map<int,bool> visited;

struct state{
    int r,c,num,ti;
    vector<int> v;
};

queue<state> q;

int changetoint(char c){
    for(int i=0;i<9;i++){
        if(c == alphabet[i]) return i+1;
    }
}

int visited_num(){
    int cnt = 0;
    for(int i=0;i<3;i++){
        int check = 0;
        for(int j=0;j<3;j++){
            check = 10*check+board[i][j];
        }
        cnt = 1000*cnt+check;
    }
    return cnt;
}

void change(int before,int r1,int c1,int r2,int c2){
    memset(board,-1,sizeof(board));
    for(int i=2;i>=0;i--){
        for(int j=2;j>=0;j--){
            board[i][j] = before%10;
            before /= 10;
        }
    }
    int temp = board[r1][c1];
    board[r1][c1] = board[r2][c2];
    board[r2][c2] = temp;
}

void bfs(){
    while(!q.empty()){
        state p = q.front();
        q.pop();
        if(p.num == 123456789){
            printf("%d\n",p.ti);
            for(int i: p.v){
                printf("%d ",i);
            }
            return;
        }
        for(int i=0;i<4;i++){
            int nr = p.r+dr[i];
            int nc = p.c+dc[i];
            if(nr<0 || nc<0 || nr>=3 || nc>=3) continue;
            change(p.num,p.r,p.c,nr,nc);
            int new_num = visited_num();
            if(visited.find(new_num) != visited.end()) continue;
            visited[new_num] = true;
            vector <int> newv = p.v;
            newv.push_back(board[p.r][p.c]);
            q.push({nr,nc,new_num,p.ti+1,newv});
        }
    }
    return;
}

int main()
{
    char c;
    int fr,fc;
    vector<int> fv;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>c;
            board[i][j] = changetoint(c);
            if(c == 'X'){
                fr = i, fc = j;
            }
        }
    }
    q.push({fr,fc,visited_num(),0,fv});
    bfs();
    return 0;
}
