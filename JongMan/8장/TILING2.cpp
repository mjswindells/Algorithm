#include <iostream>

using namespace std;
//TILING2
//https://algospot.com/judge/problem/read/TILING2

//간단한 DP문제 피보나치와 같은 느낌으로 생각하자
//  n번째 타일을 구한다할 경우
//   a        b       c
//  ㅁㅣ     ㅁ=      ㅁㅣㅣ 이라고 생각하자
//a에서의 ㅁ는 n-1이고 b와c에서의 ㅁ는 n-2일때이다.
//이때 a와 c 는 사실상 같은 경우이다.
//처음 생각했을때 ans[i]=(ans[i-2]*2+ans[i-1])로 2칸전에것은 2배를 해야하나
//생각했지만 사실 겹치므로 그냥 피보나치와 같은 알고리즘으로 구할 수 있다.

int ans[101];
void FindAns(){
    ans[1]=1;
    ans[2]=2;
    for(int i=3;i<101;i++){
        ans[i]=(ans[i-2]+ans[i-1])%1000000007;
    }
}
int main(){
    int T,n; cin>>T;
    FindAns();
    while(T--){
        cin>>n;
        cout<<ans[n]<<endl;
    }
}