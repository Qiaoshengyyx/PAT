#include<bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    float profit = 1, tmp = 0, a;
    char res[3] = {'W','T','L'}, ch;
    for(int i=0; i<3; i++){
        tmp = 0;
        for(int j=0; j<3; j++){
            cin>>a;
            if(a > tmp){
                tmp = a;
                ch = res[j];
            }
        }
        printf("%c ", ch);
        profit*=tmp;
    }
    profit = (profit * 0.65 - 1) * 2;
    printf("%.2lf", profit);
    return 0;
}
