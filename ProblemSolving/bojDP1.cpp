#include <iostream>
//백준 1003번
//간단한 피보나치 문제
//2차원 배열로 0의 개수와 1의 개수를 메모리제이션하자

using namespace std;
int fibo[41][2]; 
void fibonacci() {
    fibo[0][0]=1;
    fibo[0][1]=0;
    fibo[1][0]=0;
    fibo[1][1]=1;
    for(int i=2;i<41;i++){
        fibo[i][0]=fibo[i-2][0]+fibo[i-1][0];
        fibo[i][1]=fibo[i-2][1]+fibo[i-1][1];
    }
}

int main(){
    int N,c,zero,one; cin>>N;
    fibonacci();
    while(N--){
        cin>>c;
        zero=fibo[c][0];
        one=fibo[c][1];
        cout<<zero<<" "<<one<<endl;
    }
}