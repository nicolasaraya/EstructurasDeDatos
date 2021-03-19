#include <bits/stdc++.h>
#include "PriorityQueueHeap.h"
#include "PriorityQueueUnsorted.h"
#include <time.h>

using namespace std;

void HeapSort(vector<int> &vec){  //O(n logn)
	PriorityQueueHeap* pqh = new PriorityQueueHeap();
	for(int i = 0; i<vec.size(); i++) pqh->push(vec.at(i));
	vec.clear();


	while(!pqh->empty()) {
		vec.push_back(pqh->top());
		pqh->pop();
	}
}

void SelectionSort(vector<int> &vec){ //O(n^2)
	PriorityQueueUnsorted* pqu = new PriorityQueueUnsorted();
	for(int i = 0; i<vec.size(); i++) pqu->push(vec.at(i)); 
	vec.clear();
	while(!pqu->empty()) {
		vec.push_back(pqu->top()); 
		pqu->pop();
	}
}

int main(){
	srand(time(NULL));
	vector<int> v1, v2;
	int n = 100;
	for(int i = 0; i<n; i++){
		int x = rand()%(n*10);
		v1.push_back(x);
		v2.push_back(x);
	}

	HeapSort(v1);
	SelectionSort(v2);


	cout<<"HeapSort: "<<endl;
	for(int i = 0; i<n; i++){
		cout<<v1.at(i)<<" ";
	}
	cout<<endl;


	cout<<"SelectionSort: "<<endl;
	for(int i = 0; i<n; i++){
		cout<<v2.at(i)<<" ";
	}
	cout<<endl; 





	return 0;
}