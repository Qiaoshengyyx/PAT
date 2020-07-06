#include<bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<double> A(1010,0),res(2010, 0); // 相乘后指数会更大
    vector<int> v;
    int N, K, maxz = 0, num = 0;
    double a;
    cin>>K;
    for(int i=0; i<K; i++){
        cin>>N;
        cin>>A[N];
        v.push_back(N);
    }
    cin>>K;
    for(int i=0; i<K; i++){
        cin>>N>>a;
        for(int j=0; j<v.size(); j++){
            int newN = v[j] + N;
            maxz = max(maxz, newN);
            res[newN] += A[v[j]] * a;
        }
    }
    for(int i=0; i<=maxz; i++)
        if(res[i] != 0) num++;
    printf("%d", num);
    for(int i=maxz; i>=0; i--){
        if(res[i] != 0) printf(" %d %.1lf", i, res[i]);
    }
    return 0;
}
