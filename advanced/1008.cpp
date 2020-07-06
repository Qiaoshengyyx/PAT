#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int N, now = 0, f, sum = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> f;
        if(f > now){
            sum += (f - now) * 6;
        }else if(f < now){
            sum += (now - f) * 4;
        }
        sum += 5;
        now = f;
    }
    cout<<sum;
    return 0;
}
