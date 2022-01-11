#include <iostream>
#include <vector>

using namespace std;
//0번째 idx부터 N번째 idx까지 돌며 최소값을 가지는 idx와 0번째 idx를 swap
//1~N 중 최소값을 가지는 idx를 찾아 1번째 idx와 swap
//반복 
//O(n^2)
void SelctionSort(vector<int>& v){
    for(int i=0;i<v.size();i++){
        int minival = v[i];
        int idx =i;
        for(int j=i+1;j<v.size();j++){
            if(v[j]<minival) {
                minival=v[j];
                idx=j;
            }
        }
        swap(v[i],v[idx]);
    }
}
int main(){
    vector<int> a ={1,3,7,6,4,5,8,3,10,32,23};
    for(auto n : a){
        cout<<n<<' ';
    }
    SelctionSort(a);
    cout<<endl;
    for(auto n : a){
        cout<<n<<' ';
    }
}