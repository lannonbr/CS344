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
vector<T> insertionsort(vector<T> & vec) {

}

int main() {
	vector<int> v = {3,12,9,5,20, 123,345, 13 ,678 ,134, 869, 1, 34 ,78, 666, 420, 69};
	quicksort(v, 0, v.size()-1);
	for(int i : v)
		cout << i << '\n';
	return 0;
}
