#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
//PACKING
//https://algospot.com/judge/problem/read/PACKING
//배낭문제 유형
//https://www.acmicpc.net/problem/12865

// 물건수, 캐리어 용량
int N,W;
string stuff[100];
int volume[100], urgency[100];

int cache[1001][100];

//캐리어에 남은 용량이 capacity일 때 item이후의 물건들을
//담아 얻을 수 있는 최대 절박도의 합 return
int MaxUrgency(int capacity,int item){
    //기저사례: 더 담을 물건이 없을 때
    if(item==N) return 0;
    int& ret=cache[capacity][item];
    if(ret!=-1) return ret;
    //이 물건을 담지 않을 경우
    ret=MaxUrgency(capacity,item+1);
    //이 물건을 담을 경우
    if(capacity>=volume[item]){
        ret=max(ret,MaxUrgency(capacity-volume[item],item+1)+urgency[item]);
    }
    return ret;
}

// MaxUrgency이 선택한 물건들의 목록을 picked에 저장한다
void reconstruct(int capacity, int item, vector<string>& picked){
    //기저사례 : 모든 물건을 다 고려했음
    if (item == N) return;
    // item+1과item이 같을 경우 item을 선택하지 않고 최대절박도를 구했다는 의미
    if (MaxUrgency(capacity, item) == MaxUrgency(capacity, item + 1)){
        reconstruct(capacity, item + 1, picked);
    }
    else{
        picked.push_back(stuff[item]);
        reconstruct(capacity - volume[item], item + 1, picked);
    }
}

int main(){
   int T; cin>>T;
   while(T--){
       cin>>N>>W;
       vector<string> picked;
       for(int i=0;i<N;i++){
           cin>>stuff[i]>>volume[i]>>urgency[i];
           for(int j=0;j<1001;j++) cache[j][i]=-1;
       }
        reconstruct(W, 0, picked);
        cout << MaxUrgency(W, 0) << " " << picked.size() << endl;
        for (int j = 0; j < picked.size(); j++) cout << picked[j] << endl;
        for(int i=0;i<W+1;i++){
            for(int j=0;j<N;j++) cout<<cache[i][j]<<" ";
            cout<<endl;
        }
   } 
}