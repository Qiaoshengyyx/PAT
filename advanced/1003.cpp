#include <bits/stdc++.h>
using namespace std;
const int inf = 1e7;
int main(int argc, const char * argv[]) {
    int N, M, C1, C2, a, b, dis;
    scanf("%d%d%d%d",&N,&M,&C1,&C2);
    vector<int> teams(N), collect(N,0);
    int edge[510][510];
    fill(edge[0], edge[0]+510*510, -1);
    for(int i=0; i<N; i++)
        scanf("%d",&teams[i]);
    for(int i=0; i<M; i++){
        scanf("%d%d%d",&a,&b,&dis);
        edge[a][b] = dis;
        edge[b][a] = dis;
    }
    vector<int> Dist(N, inf);
    vector<int> path(N, 0);
    vector<bool> Visit(N, false);
    Dist[C1] = 0;
    path[C1] = 1;
    collect[C1] = teams[C1];
    for(int i=0; i<N; i++){
        int u = -1;
        int mindis = inf;
        for(int j=0; j<N; j++){
            if(!Visit[j] && Dist[j] < mindis){
                u = j;
                mindis = Dist[j];
            }
        }
        if(u == -1) break;
        Visit[u] = true;
        for(int k=0; k<N; k++){
            if(!Visit[k] && edge[u][k] != -1){
                if(edge[u][k] + Dist[u] < Dist[k]){
                    Dist[k] = edge[u][k] + Dist[u]; // 更新最短距离
                    collect[k] = collect[u] + teams[k]; // 更新救援队数
                    path[k] = path[u]; //更新路径数量
                }else if(edge[u][k] + Dist[u] == Dist[k]){
                    path[k] += path[u];
                    collect[k] = max(collect[k], teams[k] + collect[u]);
                }
            }
        }
    }
    printf("%d %d",path[C2], collect[C2]);
    return 0;
}
