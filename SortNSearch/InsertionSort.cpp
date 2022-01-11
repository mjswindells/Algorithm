#include <iostream>
#include <vector>

using namespace std;
//0~N까지 순회를 한다
//k번째일 경우 0~(k-1)까지를 S1이라 하자 이때 S1은 정렬된 상태이다
//S1의 k-1부터 역순으로 k번째 원소가 들어갈 위치까지 swap을 반복한다
//최선의 경우 O(N)
//최악의 경우 O(N^2)
void InsertionSort(vector<int>& v){
    for(int i=1;i<v.size();i++){
        int j=i;
        //S1에서 i가 들어갈 위치까지 swap하는 과정
       while((j>0)&&(v[j-1]>v[j])){
            swap(v[j],v[j-1]);
            j--;
        }
    }
}

int main(){
    vector<int> a ={1,3,7,6,4,5,8,3,10,32,23};
    for(auto n : a){
        cout<<n<<' ';
    }
    InsertionSort(a);
    cout<<endl;
    for(auto n : a){
        cout<<n<<' ';
    }
}