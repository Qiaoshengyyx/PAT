#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int n1,n2,z, maxz=0,num=0;
    double d;
    cin>>n1;
    vector<double> res(1010,0);
    for(int i=0; i<n1; i++){
        cin>>z>>d;
        res[z] += d;
        maxz = max(z, maxz);
    }
    cin>>n2;
    for(int i=0; i<n2; i++){
        cin>>z>>d;
        res[z] += d;
        maxz = max(z, maxz);
    }
    for(int i=maxz; i>=0; i--){
        if(res[i] != 0) num++;
    }
    cout<<num;
    while(maxz!=0 && res[maxz] == 0) maxz--;
    for(int i=maxz; i>=0; i--){
        if(res[i] != 0)
            printf(" %d %.1lf",i, res[i]);
    }
    return 0;
}
