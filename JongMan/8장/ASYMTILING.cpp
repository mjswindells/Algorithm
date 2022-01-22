#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;
//ASYMTILING
//https://algospot.com/judge/problem/read/ASYMTILING
//타일 중간에 어떤것이 오냐에 따라 결정된다
// ㅁㅣㅁ , ㅁ=ㅁ , ㅁㅁ 이렇게 3가지로 분류가 가능
// 홀       짝      짝
// 타일이 5개일 경우와 6개일 경우 (작은경우)에서 생각해보자


//tile 은 전체타일링의 수
//cache는 비대칭 타일링의 수
int tile[101];
int cache[101];
const int MOD = 1000000007;

//테스트케이스가 1~50이므로 배열에 담아두고 바로바로 출력할 수 있게 설정하였다.
void symmetry(){
    tile[1]=1;tile[2]=2;
    cache[0]=cache[1]=cache[2]=0;

    for(int i=3;i<101;i++){
        tile[i]=(tile[i-2]+tile[i-1])%MOD;
        //짝수 : 굳이 2개로 나눈 이유는 하나로 합쳤을경우 범위의 오류로 인해 
        //원하는 답이 출력되지 않는다.
        if(i%2==0){
            //MOD를 더하고 나머지를 구하는 이유는 뺀 값이 음수가 나올 수 있기에 더해주고 나머지를 구한다.
            cache[i]=(tile[i]-tile[i/2-1]+MOD)%MOD;
            cache[i]=(cache[i]-tile[i/2]+MOD)%MOD;
        }
        //홀수
        if(i%2==1){
            cache[i]=(tile[i]-(tile[i/2])+MOD)%MOD;
        }
    }

}

int main(){
    int T,N;cin>>T;

    symmetry();

    while(T--){
        cin>>N;
        cout<<(int)(cache[N])<<endl;
    }
}