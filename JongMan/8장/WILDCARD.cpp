#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
//WILDCARD
//https://algospot.com/judge/problem/read/WILDCARD


int cache[101][101];
string W, S;

bool matchMemoized(int w, int s)
{
	int& ret = cache[w][s];
	if (ret != -1)	return ret;
	//W[w]와 S[s]를 맞춰나간다
	if (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s]))
	{
		return ret = matchMemoized(w + 1, s + 1);
	}
	//더 이상 대응할수 없으면 왜 while문이 끝났는지 확인한다.
	//2. 패턴 끝에 도달해서 끝난 경우 : 문자열도 끝났어야 참
	if (w == W.size()) 
		return ret = (s == S.size());

	//4. *를 만나서 끝난 경우 : *에 몇글자를 대응해야 할지 재귀 호출하면서 확인
	if (W[w] == '*')
		if (matchMemoized(w + 1, s ) || (s < S.size() && matchMemoized(w, s+1)))
			return ret = 1;

	//3. 이외의 경우에는 모두 대응되지 않는다.
	return false;
}

int main(){
    int T,n;   
    vector<string> ans;
    cin>>T;
    while(T--){
        ans.clear();
        cin>>W>>n;
        while(n--){
            memset(cache,-1,sizeof(cache));
            cin>>S;
            if(matchMemoized(0,0)) ans.push_back(S);
        }
        sort(ans.begin(),ans.end());

        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<endl;
        }
    }
}