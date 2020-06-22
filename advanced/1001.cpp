#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int a, b, c;
    cin>>a>>b;
    string s;
    c = a+b;
    if(c < 0) cout<<"-";
    s = to_string(abs(c));
    int i = s.size() % 3 == 0 ? 3 : s.size() % 3;
    cout<<s.substr(0, i);
    for(i; i<s.size(); i+=3)
        cout<<","<<s.substr(i,3);
    return 0;
}
