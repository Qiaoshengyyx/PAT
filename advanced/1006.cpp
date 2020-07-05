#include<bits/stdc++.h>
using namespace std;
int calTime(string time){
    int h = stoi(time.substr(0,2));
    int m = stoi(time.substr(3,2));
    int s = stoi(time.substr(6,2));
    return h*3600 + m*60 + s;
}
int main(int argc, const char * argv[]) {
    int N, unlocktime=INT_MAX, locktime=0;
    cin>>N;
    string id1, id2, id, in, out;
    for(int i=0; i<N; i++){
        cin>>id>>in>>out;
        int intime = calTime(in);
        int outtime = calTime(out);
        if(intime < unlocktime){
            id1 = id;
            unlocktime = intime;
        }
        if(outtime > locktime){
            id2 = id;
            locktime = outtime;
        }
    }
    cout<<id1<<" "<<id2;
    return 0;
}
