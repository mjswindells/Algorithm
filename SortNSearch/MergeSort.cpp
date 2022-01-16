#include <iostream>
#include <vector>

using namespace std;

//병합과정  (vector,시작idx,끝idx)
void merge(vector<int>& arr, int left, int right) {
    //copy vector
    vector<int> sorted(arr.size());
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;

	int index_sorted = left;
    //  s1          s2
    //0 1 2 3        4 5 6 7    <-idx
    //{2 4 8 9}     {3 4 10 11}
    //이 경우 i=0 j=4
    //밑에 알고리즘을 실행했을 때
    // {2 3 4 8 9}로 정렬이 된 sorted vector가 하나 나오고
    //s2에는 아직 10 과 11이 남아있다.
	while (i <= mid && j <= right) {
		if (arr[i] > arr[j]) sorted[index_sorted++] = arr[j++];
		else sorted[index_sorted++] = arr[i++];
	}

    //위에서 남은 s2를 대입하는 과정 대입인 이유는 항상 s1,s2는 정렬된 상태이다.
	if (i > mid) while (j <= right) sorted[index_sorted++] = arr[j++];
	else while (i <= mid) sorted[index_sorted++] = arr[i++];

	//arr에 재배치된 배열 업데이트
	for (int a = left; a <= right; ++a) {
		arr[a] = sorted[a];
	}
}


void mergeSort(vector<int>& arr, int left, int right) {
    //reft >= right인 경우는 원소가 1개일 때이므로 나눌 필요가 없다.
	if (left < right) {
		int mid = (left + right) / 2;
        //mergeSort를 먼저 실행함으로 제일 작은 size까지 줄인 후
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
        //작은 사이즈부터 점점 커지게 병합을 한다.
		merge(arr, left, right);
	}
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
	mergeSort(arr, 0, amount - 1);

	for (int i = 0; i < amount; ++i)
		cout << arr[i] << " ";
	cout << '\n';
}