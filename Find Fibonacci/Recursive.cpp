#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int fibonacci_recursive(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    }
}

int main() {
    int n_values[] = {10, 25, 30, 40, 50};
    int size = sizeof(n_values) / sizeof(n_values[0]);

    for (int i = 0; i < size; ++i) {
        int n = n_values[i];
        auto start = high_resolution_clock::now();
        int result = fibonacci_recursive(n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Fibonacci (rekursif) untuk n=" << n << " adalah " << result


             << " (Waktu Eksekusi: " << duration.count() << " mikrodetik)" << endl;
    }

    return 0;
}


//dikarenakan jika ukuran data n= 50 akan memakan banyak waktu menggunakan rekursif, jadi digunakan teknik memoization
#include <iostream>
#include <chrono>
#include <unordered_map>

using namespace std;
using namespace std::chrono;

unordered_map<int, long long> memo;

long long fibonacci_recursive(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (memo.find(n) != memo.end()) {
        return memo[n];
    } else {
        memo[n] = fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
        return memo[n];
    }
}

int main() {
    int n_values[] = {10, 25, 30, 40, 50};
    int size = sizeof(n_values) / sizeof(n_values[0]);

    for (int i = 0; i < size; ++i) {
        int n = n_values[i];
        auto start = high_resolution_clock::now();
        long long result = fibonacci_recursive(n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Fibonacci (rekursif dengan memoization) untuk n=" << n << " adalah " << result
             << " (Waktu Eksekusi: " << duration.count() << " mikrodetik)" << endl;
    }

    return 0;
}
