#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

const int MAX_NUM=98765;
const int N=98765;
bool isPrime[N+1];
int min_factor[N+1];



void eratosthenes(){
    memset(isPrime,1,sizeof(isPrime));
    // 1은 항상 예외처리
    isPrime[0]=isPrime[1]=false;
    // 루트N 까지만 찾아도 N이 소수인지 판별가능
    // 따라서 N이하의 모든 수가 소수인지 아닌지 판별가능
    int sqrtn=int (sqrt(N));
    
    for(int i=2;i<=sqrtn;i++){
        if(isPrime[i]){
            // i*i부터 flase로 바꾸는 이유는 i*2,i*3,'''는 이미 2와 3의 배수를 지우는 과정에서 지워졌기때문
            for(int j=i*i;j<=N;j+=i){
                isPrime[j]=false;
            }
        }
    }
}


void SieveEratos(){
  int sqrtn = int(sqrt(MAX_NUM));

  for(int i=2; i<=MAX_NUM ; ++i)
    min_factor[i] = i;  //일단 모든 min_factor를 i 값을 해당 값으로 초기화
  
  for(int i=2; i<=sqrtn ; ++i)
    if(min_factor[i] == i)  //i가 소수인 경우만
      for(int j = i*i; j<=MAX_NUM ; j+=i)
        if(min_factor[j] ==j )  //체로 걸러지지 않은 경우 i가 j의 최소 소인수이다.
          min_factor[j] = i;
}

//n의 소인수들을 반환
vector<int> factor(int n){
  vector<int> ret;
  while(n>1){  //n이 1이 될때 까지
    ret.push_back(min_factor[n]);
    n /= min_factor[n];
  }
  return ret;
}


int main(){
    eratosthenes();
    for(int i=2;i<N;i++){
        if(isPrime[i]) cout<<i<<" ";
    }
}