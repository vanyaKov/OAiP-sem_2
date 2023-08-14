#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v(100000);
    for (int i = 0; i < v.size(); i++) {
        v[i] = i;
    }

    vector<int> results(100000);

    for (int i = 0; i < results.size(); i++) {
        int sum = 0;
        for (int j = 0; j < v.size(); j++) {
            sum += v[j];
        }
        results[i] = sum;
    }
    
    int sum = 0;
    for (int i = 0; i < results.size(); i++) {
        sum +=results[i];
    }
    cout << sum;

    return 0;
}
