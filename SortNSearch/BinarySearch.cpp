#include <iostream>
#include <vector>

using namespace std;
//조건 : v는 오름차순으로 정렬돼있어야한다
// x 가 v에 속할경우 idx를 return 속하지 않을경우 -1 return
// O(lgN)
int binarySearch(vector<int> v , int x){
    //초기설정 low는 시작값 hi는 끝값
    int lo=-1, hi=v.size();
    while(lo+1<hi){
        int mid=(lo+hi)/2;
        if(v[mid]==x) return mid;
        else if(v[mid]>x) hi=mid;
        else lo=mid;
    }
    return -1;
}


int main(){
    vector<int> a ={1,3,3,4,5,6,7,8,10,23,32};
    for(auto n : a){
        cout<<n<<' ';
    }
    cout<<endl<<binarySearch(a,6);
}