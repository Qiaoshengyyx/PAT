#include<bits/stdc++.h>
using namespace std;
map<char, int> char2int;
long long getNum(string s, long long r){
    // 转化为十进制
    long long sum = 0, p = 0;
    for(long long i = s.size() - 1; i>=0; i--){
        sum += pow(r, p++) * char2int[s[i]];
    }
    return sum;
}
long long find_radix(string s, long long num){
    long long low = char2int[*max_element(s.begin(), s.end())] + 1;
    long long high = max(num, low);
    while(low <= high){
        long long mid = (low + high) / 2;
        long long t = getNum(s, mid);
        if(t > num || t < 0) high = mid - 1;
        else if(t == num) return mid;
        else low = mid + 1;
    }
    return -1;
}
int main(){
    for(int i=0; i<10; i++)
        char2int[i + '0'] = i;
    for(int i=0; i<26; i++)
        char2int['a' + i] = i + 10;
    string N1, N2, tmpN;
    long long num, tag, radix;;
    cin>>N1>>N2>>tag>>radix;
    if(tag == 1){
        num = getNum(N1, radix);
        tmpN = N2;
    }else{
        num = getNum(N2, radix);
        tmpN = N1;
    }
    long long  r = find_radix(tmpN, num);
    if(r != -1)
        printf("%lld", r);
    else
        printf("Impossible");
    return 0;
}
