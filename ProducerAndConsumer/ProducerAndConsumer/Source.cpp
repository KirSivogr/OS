#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
using namespace std;

mutex m;
bool flag = false;
int produce_data = 0;
int number;
condition_variable cv;

bool isPrime(int n) {
    if (n == 1 || n == 0) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    } 
    return true;
}

int produceData() {
    int ans = number + 1;
    while (!isPrime(ans++)) {};
    return ans - 1;
}

void consumeData(int data) {
    cout << "consume data: " << data << endl;
}

void consumer() {
    unique_lock<mutex> ul(m);
    cv.wait(ul, []() { return flag == true; });
    consumeData(produce_data);
    flag = false;
    ul.unlock();
    cv.notify_one();
}

void producer() {
    unique_lock<mutex> ul(m);
    produce_data = produceData();
    flag = true;
    ul.unlock();
    cv.notify_one();
    ul.lock();
    cv.wait(ul, []() { return flag == false; });
}

int main() {
    cin >> number;
    thread t1(consumer);
    thread t2(producer);
    t1.join();
    t2.join();
    return 0;
}