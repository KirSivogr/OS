#include <mutex>

using namespace std;

class RWLock {
public:
	void read() {
		unique_lock<mutex> ul(m);
		while (flag) {
			cv_readingAllowed.wait(ul);
		}
		readLocked++;
	}

	void write() {
		unique_lock<mutex> ul(m);
		while (flag && readLocked != 0) {
			cv_writingAllowed.wait(ul);
		}
		flag = true;
	}
private:
	mutex m;
	condition_variable cv_readingAllowed, cv_writingAllowed;
	bool flag = false;
	int readLocked = 0;
};