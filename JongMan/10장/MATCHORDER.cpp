#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//출전순서 정하기
//정렬을 이용해서 구해봤다.

int main(){
    int T,N; cin>>T;
    while(T--){
        cin>>N;
        int Mteam[N],Uteam[N];
        for(int i=0;i<N;i++) cin>>Uteam[i];
        for(int i=0;i<N;i++) cin>>Mteam[i];
        sort(Uteam,Uteam+N);
        sort(Mteam,Mteam+N);
        int count=0,U=0,M=0;
        while(M<N){
            if(Uteam[U]<=Mteam[M]){
                count++;U++;M++;
            }
            else M++;
        }
        cout<<count<<endl;
    }
}