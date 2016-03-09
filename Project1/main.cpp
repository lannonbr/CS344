#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "integer.h"
using namespace std;

void create_sorted(vector<Integer> & v, int n);
void create_reverse_sorted(vector<Integer> & v, int n);
void create_random(vector<Integer> & v, int n);

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
	vector<Integer> v;
	create_sorted(v, 100);
	insertionsort(v, 0, v.size()-1);
	for(Integer i : v)
		cout << i.get_value() << ' ';
	cout << "\n\n";
	v.clear();

	create_reverse_sorted(v, 100);
	insertionsort(v, 0, v.size()-1);
	for(Integer i : v)
		cout << i.get_value() << ' ';
	cout << "\n\n";
	v.clear();

	srand(time(NULL));

	int num_rand = 4;
	for (int i = 0; i < num_rand; i++) {
		create_random(v, 100);
		insertionsort(v, 0, v.size()-1);
		for(Integer i : v)
			cout << i.get_value() << ' ';
		cout << "\n\n";
		v.clear();
		// Make the thread sleep for 1 second to make each vector not use the same random numbers
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
	return 0;
}


void create_sorted(vector<Integer> & v, int n) {
	for(int i = 1; i <= n; i++) {
		v.push_back((Integer)i);
	}
}
void create_reverse_sorted(vector<Integer> & v, int n) {
	for(int i = n; i >= 1; i--) {
		v.push_back((Integer)i);
	}
}

void create_random(vector<Integer> & v, int n) {
	for (int i = 0; i < n; i++) {
		v.push_back((Integer)(rand()%1000));
	}
}
