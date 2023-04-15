#include <iostream>
#include <stack>
using namespace std;
int main(int argc, char *argv[]) {
	int n, a = 0;
	stack<int> steck;
	stack<int>steck1;
	stack<int>steck2;
	for (;;) {
		if (n == 0) {
			break;
		}
		cin >> n;
		steck.push(n);
		a++;
	}
	
	for (int i = 0; i < a; i++) {
		if (steck.top() > 50) {
			steck1.push(steck.top());
		}
		if (steck.top() < 50){
			steck2.push(steck.top());
		}
		steck.pop();
	}
	
	for (int i = 0; i < a; i++) {
		cout << steck1.top() << ' ';
		steck1.pop();
	}
	cout << endl;
	for (int i = 0; i < a; i++) {
		cout << steck2.top() << ' ';
		steck2.pop();
	}
}
