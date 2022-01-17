#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//pivot을 선정하는 방법에 따라 속도가 달라진다. 랜덤배열에서 빠른 속도를 보임.
//배열이 역순으로 정렬된 경우나 정렬된 경우 매우 느린 속도 O(n^2);
//평균적으로 O(nlgn)지만 병합정렬보다 평균적으로 20%빠르다
//일반적으로 n번씩 탐색하면 반으로 쪼개며 들어간다(lgn) 따라서 nlgn 

void QuickSort(vector<int>& array,int start,int end){
    //기저사례 : 원소가 1개일 경우 
    if(start>=end) return;

    //pivot을 array의 첫번째 원소로 설정한다.
    // left는 pivot+1 right는 end
    int pivot =start;
    int left = start+1;
    int right = end;

    while(left<=right){
        //{5,8,4,3,9,6,1}
        //pivot = 0 left=1 right =6
        //pivot보다 큰 첫번째 원소를 찾는 과정(left가 end까지 가기 전까지)
        while(array[pivot]>=array[left]&&left<=end) left++;
        //pivot보다 작은 원소를 array의 마지막부분부터 찾는 과정(right가 start보다 클 때까지)
        while(array[pivot]<=array[right]&&right>start) right--;
        //left=1 right=6

        if(left>right) swap(array[pivot],array[right]);
        //일반적으로 else부분이 실행된다
        //{5,1,4,3,9,6,8} => left=4 right=3
        //{3,1,4,5,9,6,8}
        else swap(array[left],array[right]);
    }
    //Q(0,2)  Q(3,6)
    QuickSort(array,start,right-1);
    QuickSort(array,right+1,end);
}

int main() {
	int amount;
	cout << "amout : ";
	cin >> amount;
    vector<int> arr(amount);
	for (int i = 0; i < amount; ++i) {
		arr[i] = rand() % 10;
	}

	for (int i = 0; i < amount; ++i)
		cout << arr[i] << " ";
	cout << '\n';
	QuickSort(arr, 0, amount - 1);

	for (int i = 0; i < amount; ++i)
		cout << arr[i] << " ";
	cout << '\n';
}