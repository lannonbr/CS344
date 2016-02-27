#include <iostream>
#include <vector>
using namespace std;

template <class T>
int partition(vector<T> & vec, int p, int r) {
 	T pivot = vec[r];
	int i = p-1;
	for (int j = p; j <= r; j++) {
		if (vec[j] <= pivot) {
			i++;
			T temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
		}
	}
	return i;
}

template <class T>
void quicksort(vector<T> & vec, int p, int r) {
	if (p < r) {
		int q = partition(vec, p, r);
		quicksort(vec, p, q-1);
		quicksort(vec, q+1, r);
	}
}

template <class T>
void insertionsort(vector<T> & vec) {
	for(int i = 0; i < vec.size(); i++) {
		T tmp = vec[i];
		int j = i-1;
		while(i >= 1 && vec[j] > tmp) {
			vec[j+1] = vec[j];
			j--;
		}
		vec[j+1] = tmp;
	}
}

int main() {
	vector<int> v = {3,12,9,5,20, 123,345, 13 ,678 ,134, 869, 1, 34 ,78, 666, 420, 69};
	quicksort(v, 0, v.size()-1);
	for(int i : v)
		cout << i << '\n';

	vector<int> v2 = {3,12,9,5,20, 123,345, 13 ,678 ,134, 869, 1, 34 ,78, 666, 420, 69};
	insertionsort(v2);
	for(int i : v2)
		cout << i << '\n';
	return 0;
}
