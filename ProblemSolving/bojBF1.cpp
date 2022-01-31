#include <iostream>
#include <vector>
using namespace std;
// 큰 수 구성하기 (브루트포스)
//https://www.acmicpc.net/problem/18511

// 처리해야할 케이스가 너무 많다 시간복잡도상 브루트포스를 사용해 풀 수 있다. 
// 21813 8 3 2
// 3333 

// 입력받을 num, 원소의 개수
int N,K;
// K개 원소를 받을 vector
vector<int> num(10);
//출력값
int ans=0;

void maxNum(int sum){
    // 값이 N보다 작거나같고 ans보다 클 경우
    if(sum<=N&&ans<sum) {
        ans=sum;
    }
    // 값이 N보다 클 경우 return
    if(sum>N) return;

    for(int i=0;i<K;i++){
        maxNum(sum*10+num[i]);
    }
    return;
}

int main(){
    cin>>N>>K;
    for(int i=0;i<K;i++) cin>>num[i];
    maxNum(0);
    cout<<ans<<endl;
}