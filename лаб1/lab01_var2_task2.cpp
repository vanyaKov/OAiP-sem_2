#include <iostream>
#include <stdarg.h>
using namespace std;
 
int sum(int n, ...)
{
    va_list arg;
    va_start(arg, n);
 
    int s = 0;
    int ar[n];
 
    for (int i = 0; i < n; i++)
        ar[i] = va_arg(arg, int);
    
    for (int i = 0; i < n; i++) {
        s += ar[i] * ar[i+1];
    }
    
    va_end(arg);
 
    return s;
}
int main() {
    cout << sum(8, 1, 2, 3, 4, 5, 6, 7, 8);
    return 0;
}