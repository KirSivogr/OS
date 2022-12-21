#include <iostream>
#include <vector>
#include <thread>
using namespace std;

long long MatrixPower(vector <vector <long long>>& m, vector <vector <long long>>& m1,
	int row, int column) {

	long long result = 0;
	for (int i = 0; i < m[0].size(); i++) {
		result += m[row][i] * m1[i][column];
	}
	return result;
}

int main() {
	long long row, column;
	long long row_, column_;

	cout << "Enter the number of rows of the first matrix: ";
	cin >> row;
	cout << "Enter the number of columns of the first matrix: ";
	cin >> column;

	cout << "Enter the number of rows of the second matrix: ";
	cin >> row_;
	cout << "Enter the number of columns of the second matrix: ";
	cin >> column_;

	if (column != row_) {
		cout << "Matrix multiplication is not possible";
		return 0;
	}

	vector <vector <long long>> firstMatrix(row, vector <long long>(column));
	vector <vector <long long>> secondMatrix(row_, vector <long long>(column_));

	cout << "Fill in the first matrix\n";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> firstMatrix[i][j];
		}
	}

	cout << "Fill in the second matrix\n";
	for (int i = 0; i < row_; i++) {
		for (int j = 0; j < column_; j++) {
			cin >> secondMatrix[i][j];
		}
	}

	vector <vector <long long>> resultMatrix(row, vector <long long>(column_));

	vector <thread> threads;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column_; j++) {
			threads.emplace_back([&resultMatrix, &firstMatrix, &secondMatrix, i, j]() {
				resultMatrix[i][j] = MatrixPower(firstMatrix, secondMatrix, i, j);
				});
		}
	}

	for (auto& i : threads) {
		i.join();
	}

	for (auto& i : resultMatrix) {
		for (auto& j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
}