#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;
//SNAIL
//https://algospot.com/judge/problem/read/SNAIL
//메모리제이션을 활용한 중복된 경우를 제외한다
// 3일에 5만큼 올라간 경우는 3번이나 나올 수 있다 이러한 경우의 중복을 제거한다

int n,m;
//m의 최대가 1000이므로 전부 비가 올 경우를 생각해 크기를 2배해준다
double cache[1000][2001];

double canclimb(int day,int climb){
    //기저사례 : m일만큼 올랐을때 높이 이상이면 1아니면 0 (확률이므로)
    if(day==m) return climb>=n?1:0;
    double& ret=cache[day][climb];

    if(ret!=-1.0) return ret;
    //75%확률로 비가 오므로
    return ret=0.25*canclimb(day+1,climb+1)+0.75*canclimb(day+1,climb+2);
}
int main(){
    int T; cin>>T;
    while(T--){
        //cache가 실수형이라 memset을 사용했을때 오류가 생긴다 주의하자.
        for(auto& r:cache){
            for (auto& c:r){
                c=-1.0;
            }
        }
        
        cin>>n>>m;
        cout.precision(10);
        cout<<canclimb(0,0)<<endl;
    }
}