#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//https://algospot.com/judge/problem/read/CLOCKSYNC
//최소값 설정을 위해 INF를 큰 값으로 설정
#define INF 987654321
//각각의 스위치 const로 설정
const vector<int> timeChain[10]={
    {0,1,2},
    {3,7,9,11},
    {4,10,14,15},
    {0,4,5,6,7},
    {6,7,8,10,12},
    {0,2,14,15},
    {3,14,15},
    {4,5,7,14,15},
    {1,2,3,4,5},
    {3,4,5,9,13}
};
//모든 시계가 0를 가르킬때 즉, 12시일때 return true
bool Oclock(int clock[]){
    for(int i=0;i<16;i++)
        if(clock[i]!=0) return false;
    return true;
}

//(배열,누를 스위치 idx)
int minTime(int clock[],int start){
    //마지막 스위치까지 누를지 선택할 때가 왔을 때 return
    //전부 12시면 0 return 이유는 밑에 재귀를 보면 알 수 있다.
    if(start==10) return Oclock(clock) ? 0 : INF;
    int ans = INF;
    //스위치는 0,1,2,3번만 눌러보면 된다 만약 4번 누르게되면
    //결국 안누르는것과 마찬가지
    for(int i=0;i<4;i++){
        //스위치를 안눌렀을때부터 재귀를 돈다 이때 스위치를 누른횟수만큼
        //추가를해서 min으로 값을 구함. 
        ans = min(ans,i+minTime(clock,start+1));
        for(int j=0;j<timeChain[start].size();j++){
            int n=timeChain[start][j];
            clock[n]=(clock[n]+3)%12;
        }
    }
    return ans;
}
int main(){
    int T,k,ans;
    cin>>T;
    while(T--){
        int clock[16];
        for(int i=0;i<16;i++) {
            cin>>k;clock[i]=k%12;
            }
        ans=minTime(clock,0);
        if(ans==INF) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}