//#include<bits/stdc++.h>
//using namespace std;
//int main(int argc, const char * argv[]) {
//    // 最大连续子序列和
//    int K, sum = -1, tmp = 0, start = 0, end = 0, j = 0;
//    bool flag = true;
//    cin>>K;
//    vector<int> v(K);
//    for(int i=0; i<K; i++){
//        cin>>v[i];
//        if(v[i] >= 0) flag = false;
//        tmp += v[i];
//        if(tmp > 0)
//            j++;
//        if(tmp > sum){
//            sum = tmp;
//            end = i;
//            start = j==0? end : end - j + 1;
//        }
//        if(tmp < 0){
//            tmp = 0;
//            j = 0;
//        }
//    }
//    if(flag) printf("0 %d %d",v[0], v[K-1]);
//    else printf("%d %d %d",sum, v[start], v[end]);
//    return 0;
//}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int K, sum = -1, tmp = 0;
    cin>>K;
    vector<int> v(K);
    int start = 0, end = K - 1, tmpindex=0;
    for(int i=0; i<K; i++){
        cin>>v[i];
        tmp += v[i];
        if(tmp < 0){
            tmp = 0;
            tmpindex = i+1;
        }else if(tmp > sum){
            start = tmpindex;
            end = i;
            sum = tmp;
        }
    }
    printf("%d %d %d",sum<0 ? 0 : sum, v[start], v[end]);
    return 0;
}
