#include <iostream>
#include <deque>
using namespace std;


int main()
{
	deque<int> dq;
	dq.push_front(20);
	dq.push_front(10);
	dq.push_back(30);
	dq.push_front(5);
	dq.push_back(40);
	dq.push_back(50);
	dq.push_front(2);
	dq.push_back(60);
	dq.pop_back();
	dq.pop_front();
	auto it=dq.begin();
	dq.insert(it,3);
	it=it+3;
	dq.insert(it,25);
	cout<<*(++it)<<endl;
	dq.erase(it);
	for(auto x: dq)
		cout << x << " ";

	cout << dq.front() << " " << dq.back()<<endl;
	cout<<*dq.cend();
	cout<<dq.size();
	return 0;
}