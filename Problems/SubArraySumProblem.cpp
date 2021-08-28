// Problem link: https://csacademy.com/ieeextreme-practice/task/46e8a03f242b875f1ae5fb84a3b4321f/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

typedef vector<long long> Matrix1D;
typedef vector<Matrix1D> Matrix2D;
typedef vector<Matrix2D> Matrix3D;
typedef vector<Matrix3D> Matrix4D;
typedef vector<Matrix4D> Matrix5D;

vector<int> dim(5);
vector<long long> vec;
Matrix5D SUM;
int SIZE;

void resizeAll(Matrix1D &v) {
	v.resize(dim[0] + 1);
	for (long long &x : v)
	    x = 0;
}
void resizeAll(Matrix2D &v) {
	v.resize(dim[1] + 1);
	for (auto &x : v)
		resizeAll(x);
}
void resizeAll(Matrix3D &v) {
	v.resize(dim[2] + 1);
	for (auto &x : v)
		resizeAll(x);
}
void resizeAll(Matrix4D &v) {
	v.resize(dim[3] + 1);
	for (auto &x : v)
		resizeAll(x);
}
void resizeAll(Matrix5D &v) {
	v.resize(dim[4] + 1);
	for (auto &x : v)
		resizeAll(x);
}

long long& access(Matrix1D &M, vector<int> &IDX) {
	return M[IDX[0]];
}
long long& access(Matrix2D &M, vector<int> &IDX) {
	return access(M[IDX[1]], IDX);
}
long long& access(Matrix3D &M, vector<int> &IDX) {
	return access(M[IDX[2]], IDX);
}
long long& access(Matrix4D &M, vector<int> &IDX) {
	return access(M[IDX[3]], IDX);
}
long long& access(Matrix5D &M, vector<int> &IDX) {
	return access(M[IDX[4]], IDX);
}

void incrementIndex(vector<int> &IDX) {
	int i = 4;
	IDX[i]++;
	while (IDX[i] == dim[i] + 1) {
		IDX[i] = 1;
		i--;
		if (i < 0) break;
		IDX[i]++;
	}
}

long long getSum(vector<int> L, vector<int> R) {
	long long ans = 0;
	vector<int> I = R;
	int sign;
	for (int i = 0; i < 32; i++) {
		sign = 0;
		for (int j = 0; j < 5; j++) {
			if ((i & (1 << j)) != 0) {
				I[j] = L[j] - 1; // L'
				sign++;
			}
			else
				I[j] = R[j];
		}
		if (sign % 2 == 1)
			ans -= access(SUM, I);
		else
			ans += access(SUM, I);
	}
	return ans;
}

void fillSum() {
	vector<int> I(5, 1);
	for (int idx = 1; idx <= SIZE; idx++) {
		access(SUM, I) -= getSum(I, I);
		access(SUM, I) += vec[idx];
		incrementIndex(I);
	}
}

int main() {
	int d;
	cin >> d;
	SIZE = 1;
	for (int i = 0; i < d; i++) {
		cin >> dim[i];
		SIZE *= dim[i];
	}
	
	for (int i = d; i < 5; i++)
	    dim[i] = 1;
	
	resizeAll(SUM);
	vec.resize(SIZE + 1);
	
	vec[0] = 0;
	for (int i = 1; i <= SIZE; i++)
		cin >> vec[i];
	
	fillSum();
	int q;
	cin >> q;

	vector<int> L(5), R(5);
	for (int i = d; i < 5; i++) {
		L[i] = 1;
		R[i] = 1;
	}

	while (q--) {
		for (int i = 0; i < d; i++)
			cin >> L[i];
		
		for (int i = 0; i < d; i++)
			cin >> R[i];
		
		cout << getSum(L, R) << endl;
	}
	
	return 0;
}
