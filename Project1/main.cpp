#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include "integer.h"
using namespace std;

vector<Integer> create_sorted(int n);
vector<Integer> create_reverse_sorted(int n);
vector<Integer> create_random(int n);

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
int rand_partition(vector<T> & vec, int p, int r) {
	srand(time(NULL));
	
	int num = p + rand() % (r-p);
	T tmp = vec[r];
	vec[r] = vec[num];
	vec[num] = tmp;

	return partition(vec, p, r);
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
void rand_quicksort(vector<T> & vec, int p, int r) {
	if (p < r) {
		int q = rand_partition(vec, p, r);
		rand_quicksort(vec, p, q-1);
		rand_quicksort(vec, q+1, r);
	}
}

template <class T>
void insertionsort(vector<T> & vec) {
	for(int i = 0; i < vec.size(); i++) {
		T tmp = vec[i];
		int j = i-1;
		while(i >= 1 && tmp < vec[j]) {
			vec[j+1] = vec[j];
			j--;
		}
		vec[j+1] = tmp;
	}
}

int main() {
	vector<Integer>v={(Integer)3,(Integer)12,(Integer)9,(Integer)5,(Integer)20,(Integer)123,(Integer)345,(Integer)13,(Integer)678,(Integer)134,(Integer)869,(Integer)1,(Integer)34,(Integer)78,(Integer)666,(Integer)420,(Integer)69};
	rand_quicksort(v, 0, v.size()-1);
	for(Integer i : v)
		cout << i.get_value() << ' ';
	cout << '\n';

	return 0;
}


vector<Integer> create_sorted(int n) {
	vector<Integer> v;
	for(int i = 1; i <= n; i++) {
		v.push_back((Integer)i);
	}
	return v;
}
vector<Integer> create_reverse_sorted(int n) {	
	vector<Integer> v;
	for(int i = n; i >= 1; i--) {
		v.push_back((Integer)i);
	}
	return v;
}

vector<Integer> create_random(int n) {
	vector<Integer> v;
	for (int i = 0; i < n; i++) {
		v.push_back((Integer)(rand()%1000));
	}
	return v;
}
