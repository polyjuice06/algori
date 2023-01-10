#include <bits/stdc++.h>
using namespace std;
const int INF1=1000000001;
const int INF2=-1000000001;
int n,q;
int A[100001];
pair<int,int> tree[400004]; //first가 최대값 second는 최솟값
inline int Min(int a, int b){ return a<b ? a : b; }
inline int Max(int a, int b){ return a<b ? a : b; }
void update(int now, int s, int e, int tgIdx, int val){
    if (s == e){ /// s == e == tgIdx 인 경우
        tree[now].first = val;
        tree[now].second = val;
        return;
    }
    int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
    if (tgIdx <= m) update(lch, s, m, tgIdx, val); /// 찾는 위치가 왼쪽(앞쪽)에 있는 경우
    else update(rch, m + 1, e, tgIdx, val); /// 찾는 위치가 오른쪽(뒤쪽)에 있는 경우
    if(tree[lch].first >= tree[rch].first){
        tree[now].first = tree[lch].first;
    }
    else{
        tree[now].first = tree[rch].first;
    }
    if(tree[lch].second <= tree[rch].second){
        tree[now].second = tree[lch].second;
    }
    else{
        tree[now].second = tree[rch].second;
    }
}
pair<int,int> query(int now, int s, int e, int fs, int fe){
    if (e < fs || fe < s) return make_pair(INF2,INF1);
    if (fs <= s && e <= fe) return tree[now];
    int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
    pair<int,int> left = query(lch, s, m, fs, fe);
    pair<int,int> right = query(rch, m + 1, e, fs, fe);
    pair<int,int> check;
    if(left.first >= right.first){
        check.first = left.first;
    }
    else{
        check.first = right.first;
    }
    if (left.second <= right.second){
        check.second = left.second;
    }
    else{
        check.second = right.second;
    }
    return check;
}

int main()
{
    scanf("%d %d",&n,&q);
    for(int i=0;i<400004;i++){
        tree[i].first = INF2;
        tree[i].second = INF1;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]);
        update(1,1,n,i,A[i]);
    }
    for(int i=0;i<q;i++){
        int st,en;
        scanf("%d %d",&st,&en);
        pair<int,int> ans;
        ans = query(1,1,n,st,en);
        printf("%d %d\n",ans.second,ans.first);
    }
    return 0;
}