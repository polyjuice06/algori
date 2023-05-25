#include <bits/stdc++.h>
using namespace std;
int MAX = 1000000;
 
int main(){
    char P[MAX+1], T[MAX+1];
    int M, N;
    gets(T);
    gets(P);
    N = strlen(T);
    M = strlen(P);
    int fail[MAX] = {0};
    for(int i=1, j=0; i<M; i++){
        while(j > 0 && P[i] != P[j]) j = fail[j-1];
        if(P[i] == P[j]) fail[i] = j++;
    }
    vector<int> ans;
    for(int i=0, j=0; i<N; i++){
        while(j > 0 && T[i] != P[j]) j = fail[j-1];
        if(T[i] == P[j]){
            if(j == M-1){
                ans.push_back(i-M+2);
                j = fail[j];
            }
            else j++;
        }
    }
    printf("%d\n", ans.size());
    for(int i: ans)
        printf("%d ", i);
}
