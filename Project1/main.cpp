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

const int SIZE = 100;

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
void insertionsort(vector<T> & vec, int p, int r) {
	for(int i = 1; i < vec.size() -1; i++) {
		T tmp = vec[i];
		int j = i-1;
		while(j >= 0 && tmp < vec[j]) {
			vec[j+1] = vec[j];
			j--;
		}
		vec[j+1] = tmp;
	}
}

int count_comparison(const vector<Integer> vec) {
	int sum = 0;
	for(Integer i : vec) sum += i.get_value();
	return sum;
}

void print_vector(const  vector<Integer> vec) {
	for(Integer i : vec)
		cout << i.get_value() << ' ';
}

template <void (*func)(vector<Integer> &, int, int)>
void runSort(const string & name) {
	vector<Integer> v;

	cout << "\n" << name << "\n\n";
	cout << "Sorted:\t";
	create_sorted(v, SIZE);
	func(v, 0, v.size()-1);
	cout << "Comp: " << count_comparison(v) << '\n';
	v.clear();

	cout << "Reverse Sorted:\t";
	create_reverse_sorted(v, SIZE);
	func(v, 0, v.size()-1);
	cout << "Comp: " << count_comparison(v) << '\n';
	v.clear();

	srand(time(NULL));

	int num_rand = 10;
	int avg = 0;
	for (int i = 0; i < num_rand; i++) {
		create_random(v, SIZE);
		func(v, 0, v.size()-1);
		avg += count_comparison(v);
		v.clear();
		// Make the thread sleep for 1 second to make each vector not use the same random numbers
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
	cout << "Random:\tComp: " << avg / float(num_rand) << '\n';
}

int main() {
	runSort<insertionsort>("Insertionsort");
	runSort<quicksort>("Quicksort");
	runSort<rand_quicksort>("RandQuicksort");
	return 0;
}


void create_sorted(vector<Integer> & v, int n) {
	for(int i = 1; i <= n; i++)
		v.push_back((Integer) i);
}
void create_reverse_sorted(vector<Integer> & v, int n) {
	for(int i = n; i >= 1; i--)
		v.push_back((Integer) i);
}

void create_random(vector<Integer> & v, int n) {
	for (int i = 0; i < n; i++)
		v.push_back((Integer) (rand()%1000));
}
