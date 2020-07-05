//
//  main.cpp
//  1004
//
//  Created by 元雨暄 on 2020/6/24.
//  Copyright © 2020 元雨暄. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
struct node{
    int val, level=0;
};
int depth=0;
vector<int> res(100, 0);
vector<vector<int> > tree(100);
void dfs(int nodeid, int level){
    if(tree[nodeid].size() == 0){
        depth = max(depth, level);
        res[level]++;
        return;
    }
    for(int i=0; i<tree[nodeid].size();i++){
        dfs(tree[nodeid][i], level+1);
    }
}
int main(int argc, const char * argv[]) {
    int N, M, kid, id, ch; // 01 -> root
    cin>>N>>M;
    for(int i=0; i<M; i++){
        cin>>id>>ch;
        for(int i=0; i<ch; i++){
            cin>>kid;
            tree[id].push_back(kid);
        }
    }
    dfs(1,0);
    for(int i=0; i<=depth; i++){
        printf("%s%d", i==0?"":" ", res[i]);
    }
    return 0;
}
