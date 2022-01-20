#include <iostream>
#include <algorithm>

using namespace std;
//TRIPATHCNT
//https://algospot.com/judge/problem/read/TRIPATHCNT

//전에 풀었던 TRIANGLEPATH 에서 변형문제다.
//FindMax()함수에서 arr를 변형시킨다 0,0에는 최종 큰값이오고
//결국 i,j에는 i,j까지 올 수 있는 최대값이 저장되는데 이를 이용해
//0,0에서 시작해서 (0+1,0)과(0+1,0+1) 중 큰 쪽으로 이동을 하면서 count를 계산한다
//만약 둘이 같다면 둘 다 이동을 해야한다.

int arr[100][100];
//arr를 정렬하는 과정
void FindMax(int n){
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<i+1;j++){
            arr[i][j]+=max(arr[i+1][j],arr[i+1][j+1]);
        }
    }
}

int countMax(int i,int j,int n){
    //기저사례 : 맨 끝부분까지 갔을 경우 길을 찾았으니 return 1
    if(i==n-1) return 1;
    int ans=0;
    //2개의 경로중 큰 값이 있는 쪽으로 이동을하면 만약 같으면 둘 다 이동한다
    if(arr[i+1][j]>=arr[i+1][j+1]) ans+=countMax(i+1,j,n);
    if(arr[i+1][j]<=arr[i+1][j+1]) ans+=countMax(i+1,j+1,n);
    return ans;
}
int main(){
    int T,n; cin>>T;
    while(T--){
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<i+1;j++){
                cin>>arr[i][j];
            }
        }
        FindMax(n);
        cout<<countMax(0,0,n)<<endl;
    }
}