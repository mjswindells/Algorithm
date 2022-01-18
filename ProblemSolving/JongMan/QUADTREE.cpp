#include <iostream>
#include <string>

using namespace std;
//QUADTREE
//https://algospot.com/judge/problem/read/QUADTREE

//분할정복은 제일 작은 경우부터 점차 넓혀가며 생각을 해보는게 좋을거 같다.

//문자열의 반복자를 인자로 사용
//반복자를 사용하는 이유 : 예를 들어 고정된 idx를 사용하면 
//재귀를 4번 도는 과정에서 처리가 힘들어진다 따라서 반복자를 사용하여
//전체 string에 대한 길이만큼 O(N) 편하게 돌기 위해

//string이 xbwwb일 때를 생각해보면 이해하기 편할것이다.
string reverse(string::iterator& it){
    char head = *(it++);
    //문자열의 첫 문자가 b나 w인 경우(사각형의 색이 같은 경우) 문자 그대로 반환
    if(head == 'b' || head == 'w')
        //head는 char이므로 string으로 바꿔주기 위해
        return string(1, head);
    //인자로 받은 문자열의 첫 번째 문자를 제외하고 나머지 문자열을 통해 재귀 호출
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    //위, 아래 조각들을 반대로 교체한다.
    // 1 2 3 4를 3 4 1 2 로 출력해야하므로.
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(){
    string str;
    int T;
    cin >> T;
	while(T--){
        cin >> str;
        string::iterator it = str.begin();
        cout << reverse(it) << endl;
    }
	
    return 0;
}