#include <bits/stdc++.h>
using namespace std;

int N, K;
int par[100010];
int arr[2010][2010];
int find(int v){
	if(v == par[v]) return v;
	return par[v] = find(par[v]);
}

bool merge(int u, int v){
	u = find(u), v = find(v);
	if(u == v) return true;
	par[u] = v;
	return false;
}

queue<pair<int,int>> q1, q2;
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void civuni(){
	while(!q1.empty()){
		int x = q1.front().first;
		int y = q1.front().second;
		q2.push(q1.front());
		q1.pop();

		for(int i=0; i<4; i++){
			int next_x = x + dr[i];
			int next_y = y + dc[i];
			if(!(0<next_x && next_x<=N && 0<next_y && next_y<=N)) continue;
			if(arr[next_x][next_y] && arr[x][y] != arr[next_x][next_y]){
				if(!merge(arr[x][y], arr[next_x][next_y])){
					K--;
				}
			}
		}
	}
}

void civpro(){
	while(!q2.empty()){
		int x = q2.front().first;
		int y = q2.front().second;
		q2.pop();

		for(int i=0; i<4; i++){
			int next_x = x + dr[i];
			int next_y = y + dc[i];
			if(!(0<next_x && next_x<=N && 0<next_y && next_y<=N)) continue;
			if(!arr[next_x][next_y]){
				arr[next_x][next_y] = arr[x][y]; 
				q1.push({next_x, next_y});
			}
			else if(arr[x][y] != arr[next_x][next_y]){
				if(!merge(arr[x][y], arr[next_x][next_y])){
					K--;
				}
			}
		}
	}
}

int main(){
	scanf("%d %d",&N,&K);
	for(int i=1; i<=K; i++){
		int a, b; 
		scanf("%d %d", &a, &b);
		arr[a][b] = i;
		q1.push({a, b});
	}
	for(int i=1; i<=100000; i++) par[i] = i;
	int ans = 0;
	while(K > 1){
		civuni();
		if(K == 1){
			printf("%d",ans); 
			return 0;
		}
		civpro();
		ans++;
	}
	printf("%d",ans);
	return 0;
}
