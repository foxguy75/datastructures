#ifndef MAXHEAP_H
#define MAXHEAP_H 
/*    file MaxHeap.h    
      author Ben Caburn 
      date November 18, 2015

      @description Implements a templated maximum queue, using a
      heap structure.
*/
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

template <class T> 
class MaxHeap {
public: 

MaxHeap(){ 
  stored = 0;
  last_index = -1;
}

void push(T value){
	if(last_index != stored - 1){
		if (last_index < 0){
			last_index++;
		}
		ret[last_index] = value;
		if(last_index){
			last_index++;
		}
	}else{
		ret.push_back(value);
		last_index++;
	}
	stored++;
	maxIsTop(ret);
	return;
}

void pop(){
	if (last_index < 0){
		return;
	}
  ret[0] = ret[last_index];
  last_index--;
  bubbleDown(ret);
  return;
}

T top(){
	if(last_index < 0){
		throw logic_error("The Heap is empty");
	}
  return ret[0];
}

unsigned int size(){
	if(last_index < 0){
		return 0;
	}
  return last_index + 1;
}

private:

vector<T> ret;
unsigned int stored;
int last_index;

void maxIsTop(vector<T>&){
	int index = last_index;
	int parent = (index - 1) / 2; // parent formual is (index - 1) / 2
	while(parent){
		if(ret[parent] < ret[index]){ // swap
			T temp = ret[parent];
			ret[parent] = ret[index];
			ret[index] = temp;
			index = parent;
			parent = (index - 1) / 2;
		}
		else{
			break;
		}
	}
	if(!parent && ret[parent] < ret[index]){ // swap
		T temp = ret[parent];
		ret[parent] = ret[index];
		ret[index] = temp;
	}
	return;
}

void bubbleDown(vector<T>&){
	for(int i = 0; i < last_index + 1; i++){
		if(ret[0] < ret[i]){
			T temp = ret[0];
			ret[0] = ret[i];
			ret[i] = temp;
		}
	}
	return;
}

};

#endif
