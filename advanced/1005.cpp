#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    string s2digit[11] = {"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string d, res;
    cin>>d;
    int sum = 0;
    for(int i=0; i<d.size(); i++){
        sum += d[i] - '0';
    }
    res = to_string(sum);
    for(int i=0; i<res.size(); i++){
        printf("%s%s", i==0? "":" ", s2digit[res[i]-'0'].c_str());
    }
    return 0;
}
