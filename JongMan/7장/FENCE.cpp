#include <iostream>
#include <algorithm>

using namespace std;

//FENCE
//https://algospot.com/judge/problem/read/FENCE
//O(nlgn) : 반으로 나누는걸 반복하고 n/2부분에서 전체를 돈다 음... 병합정렬을 생각해보자
//반으로 나눈뒤 왼쪽과 오른쪽에서 구한 넓이중 최대값을 먼저 생각해본다
//이때 중간에 걸친부분에서 값이 나올 수도 있으니 생각해준다.
int maxSum(int array[],int left,int right){
    //기저사례 : 1개인경우 그냥 높이만 rerurn한다 이게 넓이
    if(left==right) return array[left];
    //중간 idx
    int mid = (left+right)/2;
    //왼쪽과 오른쪽에서 구한 넓이중 최대값을 ans로 채택한다
    int ans = max(maxSum(array,left,mid),maxSum(array,mid+1,right));

    //가운데 두개의 넓이를 생각한다. 어차피 1개인경우는 기저사례로 뺐다.
    int lo=mid; int hi=mid+1;
    //높이는 작은걸 당연히 선택
    int height= min(array[lo],array[hi]);
    //******************생각못한부분*********************//
    //이 처리를 안하면 밑변이 2인 경우에 넓이를 선택할 수 없다.
    ans=max(ans,2*height);

    //이때 생각해야할게 중간의 넓이를 보고 left와right 끝까지 싹 가봐야한다
    //높이가 들쭉날쭉이므로 한쪽이라도 끝까지 가보지 않으면 제대로된 max를 선택할 수 없다.
    while(lo>left||hi<right){
        //우선 오른쪽 선택일경우를 보자
        //hi<right는 당연한 조건 큰 와일문에서 ||으로 처리했으니 이부분은 꼭 써줘야한다
        //lo==left 만약 왼쪽끝까지 다 갔고 오른쪽은 남아 있을경우 처리
        //(lo-1)<(hi+1) 높이가 큰 부분부터 먼저 확인을 해줘야 정확한 max를 선택가능
        //ex) 8 3 5 2 에서 높이를 고려안했을때 넓이는 (3,5,2)로 6이되고 높이는 2이다
        //그리고 (8,3,5,2)로 넓이가 8이되는데
        //높이를 고려한경우 
        //(8,3,5)로 넓이 9 높이 3
        //(8,3,5,2) 높이 2 max넓이는 9
        if((hi<right)&&(lo==left||array[lo-1]<array[hi+1])){
            hi++;
            //높이는 항상 작은걸 선택
            height=min(height,array[hi]);
        }
        else {
            lo--;
            height=min(height,array[lo]);
        }
        //넓이: 밑변(hi-lo+1)*높이
        ans=max(ans,(hi-lo+1)*height);
    }
    return ans;
}
int main(){
    int T,N;cin>>T;
    while(T--){
        cin>>N;
        int array[N];
        for(int i=0;i<N;i++) cin>>array[i];

        cout<<maxSum(array,0,N-1)<<"\n";
    }
}