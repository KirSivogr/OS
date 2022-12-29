#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

vector <bool> p;
int ans = 0;
int k = 0;
int t;
mutex mtx;

bool isPrime(int n) {
    if (n == 0 || n == 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void PrimeCheck(vector <int>& a) {
    while (true) {
        unique_lock<mutex> ul(mtx);
        if (k == a.size()) {
            return;
        }
        k++;
        t = k;
        ul.unlock();
        if (isPrime(a[t - 1]))
            p[t - 1] = 1;
    }
}
int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    p.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sz;
    cin >> sz;
    vector <thread> th;
    for (int i = 0; i < sz; i++) {
        th.emplace_back(PrimeCheck, ref(a));
    }
    for (auto& i : th) {
        i.join();
    }
    for (int i = 0; i < n; i++) {
        if (p[i]) {
            cout << a[i] << " is prime" << endl;
        }
    }
}
