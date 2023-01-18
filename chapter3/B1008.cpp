#include<iostream>
using namespace std;
#include<deque>
int main()
{
	int N,M;cin>>N>>M;
	deque<int>dq;
	for(int i=0;i<N;i++)
	{
		int x;cin>>x;
		dq.push_back(x);
	}
	while(M--)
	{
		int x=dq.back();
		dq.pop_back();
		dq.push_front(x);
	}
	cout<<dq.front();dq.pop_front();
	for(auto&e:dq)
		cout<<' '<<e;
	return 0;
}
