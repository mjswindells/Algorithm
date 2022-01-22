#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;
//LIS 최대증가부분수열
//https://algospot.com/judge/problem/read/LIS

// //O(NlogN)의 알고리즘
// // N : 탐색하는 과정 logN : lower_boud 즉 이진탐색을 통해 위치를 찾는 과정
// // [10,20,10,30,20,50,1,2,3,4,5]
// // [10] ->[10,20]->[10,20]->[10,20,30]->[10,20,30]->[10,20,30,50]
// //->[1,20,30,50]->[1,2,30,50]->[1,2,3,50]->[1,2,3,4]-> [1,2,3,4,5]
// //이런식으로 진행하며 사이즈값이 결국 최대증가부분수열이된다.
// int main(void) {
// 	int N;
// 	cin >> N;
// 	vector<int> list;
// 	for (int i = 0; i < N; i++) {
// 		int val;
// 		cin >> val;

// 		if (list.empty() || list.back() < val) //리스트가 비어있고, 리스트의 가장 큰값보다 현재값이 크다면
// 		{
// 			list.push_back(val); //리스트의 뒤에 현재 값을 추가
// 		}
// 		else
// 		{   //lower_boud(시작,끝,원하는원소)
//             //[10,20,30] 에서 val=20 이면 첫번째 idx의 위치를 가르킨다
//             //[10,20,30] 에서 val=21 이면 [10,20,21] 이 된다
// 			auto pos = lower_bound(list.begin(), list.end(), val); //해당 값의 lower bound를 구함
// 			*pos = val; //해당 위치에 값을 덮어쓰기
// 		}
// 	}

// 	cout << list.size();
// }



int arr[500],cache[500];
int N;
//O(N^2)
// 채워야하는 cache는 N이고 각 캐시마다 lis를 재귀한다
// lis의 호출마다 N의 반복문이 호출되므로 N^2
//start를 가지는 최대 부분수열을 구하는 알고리즘
//따라서 메인에서는 0~n까지중 최대값을 구해야한다.
// 9 1 3 7 5 6 20 을 생각해보면 답이 2가 나오는데 실제 답은 5이다
int lis(int start){
    int& ret=cache[start];
    //-1이 아니면 이미 start까지의 최대 부분수열의 길이를 알고있으니
    if(ret!=-1) return ret;

    ret=1;
    //start다음 idx중 큰 값을 찾는다
    for(int next=start+1;next<N;next++){
        if(arr[start]<arr[next]){
            //lis(next)보다 큰 값을 찾았으니 lis(next)+1과 비교한다
            ret=max(ret,lis(next)+1);
        }
    }
    return ret;
}

int main(){
    int T; cin>>T;
    while(T--){
        cin>>N;
        memset(cache,-1,sizeof(cache));
        for(int i=0;i<N;i++) cin>>arr[i];

        int maxlis=0;
        for(int i=0;i<N;i++) maxlis=max(maxlis,lis(i));

        cout<<maxlis<<endl;
    }
}
