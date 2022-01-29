#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
// 최대증가부분수열을 찾기

int n;
//cache[0]에 최대수열의 길이+1 ,    cache[1]: 0번째에서 만들수있는 최대 길이,'''
//choices[k] : k가 0일 때를 제외한 k-1번째에서 만들 수 있는 수열중 다음번째 idx
int cache[101], S[100], choices[101];

// S[start]에서 시작하는 증가부분수열중 최대길이를 반환
int lis4(int start){
    int& ret = cache[start+1];
    if(ret!=-1) return ret;
    //항상 S[start]는 있기 때문에 길이는 최하 1
    ret=1;
    int bestNext=-1;
    for(int next=start+1;next<n;next++){
        if(start==-1||S[start]<S[next]){
            int cand = lis4(next)+1;
            if(cand>ret){
                ret=cand;
                bestNext=next;
            }
        }
    }
    choices[start+1]=bestNext;
    return ret;
}
// S[start]에서 시작하는 LIS를 seq에 저장한다
void reconstruct(int start, vector<int>& seq){
    if(start!=-1) seq.push_back(S[start]);
    int next=choices[start+1];
    if(next!=-1) reconstruct(next,seq);
}

int main(){
    int T; cin>>T;
    while(T--){

        cout<<endl;
        vector<int> seq;
        cin>>n;
        memset(cache,-1,sizeof(cache));
        for(int i=0;i<n;i++) cin>>S[i];

        int size=lis4(-1)-1;
        reconstruct(-1,seq);
        for(int i=0;i<size;i++) cout<<seq[i]<<" ";
        cout<<endl;

        cout<<"cache"<<endl;     
        for(int i=0;i<n+1;i++) cout<<cache[i]<<" ";
        cout<<endl<<"choices"<<endl;
        for(int i=0;i<n+1;i++) cout<<choices[i]<<" ";
        cout<<endl;
    }
}
// 4
// 4
// 1 2 3 4
// 8
// 5 4 3 2 1 6 7 8 
// 8
// 5 6 7 8 1 2 3 4
// 7
// 9 1 3 7 5 6 20