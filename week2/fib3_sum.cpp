#include <bits/stdc++.h>
using namespace std;

long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

long long get_fibonacci_huge(long long n, long long m) {
    long long remainder = n % get_pisano_period(m);
	64    		
    long long first = 0;
    long long second = 1;

    long long res = remainder;

    for (int i = 1; i < remainder; i++) {
        res = (first + second) % m;
        first = second;
        second = res;
    }

    return res % m;
}

int main() {

    long long n, m = 10, temp;
    cin >> n;
    temp = get_fibonacci_huge(n+2, m);
    if (!temp)
    {
    	//Edge case baby! 
    	//Prevents printing -1 if Fib(n+2)%10 is 0
    	cout << 9;
    	return 0;
    }
    cout << ( temp - 1)%10 << '\n';
    return 0;
}