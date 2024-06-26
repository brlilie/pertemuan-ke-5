#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int fibonacci_dynamic(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    int *fib = new int[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    int result = fib[n];
    delete[] fib; // Menghapus alokasi memori

    return result;
}

int main() {
    int n_values[] = {10, 25, 30, 40, 50};
    int size = sizeof(n_values) / sizeof(n_values[0]);

    for (int i = 0; i < size; ++i) {
        int n = n_values[i];
        auto start = high_resolution_clock::now();
        int result = fibonacci_dynamic(n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Fibonacci (dynamic) untuk n=" << n << " adalah " << result
             << " (Waktu Eksekusi: " << duration.count() << " mikrodetik)" << endl;
    }

    return 0;
}
