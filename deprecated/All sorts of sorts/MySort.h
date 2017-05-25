#ifndef SORT_H
#define SORT_H
/*
 * Sort.h
 * Name: Ben Camburn, Isreal Bravo.
 *
 * November 2015
 */

#include <vector>
#include <string.h> 
#include <iostream>
#include <algorithm>

#include "MaxHeap.h"


using namespace std;

vector<int> megerSort(vector<int>&, vector<int>&);

bool isSorted(vector<int>& data){
  if(data.size() <= 1){
    return true;
  }
  for(unsigned int i = 0; i < data.size()-1; i++){
    if(data[i] > data[i+1]){
      return false;
    }
  }
  return true;
}

void selectionSort(vector<int>& data){
  for( unsigned int i = 0; i < data.size(); i++){
    int temp = data[i];
    int smallest = data[i];
    unsigned int pos = i;
    for( unsigned int k = i; k < data.size(); k++){
      if(data[k] < smallest){
        smallest = data[k];
        pos = k;
      }
    }
    data[i] = smallest;
    data[pos] = temp;
  }  
};

void bubbleSort(vector<int>& data){
  int length = data.size();
	int swap_count = 0;
	do {
		swap_count = 0;
		for(int i = 0; i < length; i++){
			if(i == length){
				break;
			}
			if(data[i] > data [i+1]){
				int temp = data[i];
				data[i] = data[i+1];
				data[i+1] = temp;
				swap_count++;
			}
		}
		length--;
	} while(swap_count);
};

void mergeSort(vector<int>& data){
  vector<int> left;
  vector<int> right;
  if(data.size() == 1 || !data.size()){
    return;
  }
  for(unsigned int i = 0; i < data.size() / 2;  i++){
    left.push_back(data[i]);
  }
  for(unsigned int i = data.size() / 2; i < data.size(); i++){
    right.push_back(data[i]);
  }
  data = megerSort(left, right);
};

void mergeSort2(vector<int>& data){
  if(data.size() < 250){
    bubbleSort(data);
    return;  
  }else{
    mergeSort(data);
    return;
  }
};

void partition(int* data, int size){
  if(size <= 1){
    return;
  }
  int pivot_value = data[rand() % size];
  //cout<< "pivot value: "<< pivot_value<<endl;
  int lower = 0;
  int upper = size - 1;
  while(lower < upper){
    while(data[lower] < pivot_value){
      lower++;
    }
    while(data[upper] > pivot_value){
      upper--;
    }
    int temp = data[lower];
    data[lower] = data[upper];
    data[upper] = temp;
  	if(data[upper] == data[lower]){
      upper--;
    }
  }
  //cout <<"lower: "<< lower<<endl;
  partition(data, lower);
  partition(&(data[lower + 1]), size - lower - 1);
}

void quickSort(vector<int>& data){
  srand((unsigned int)time(0));
  int size = data.size();
  int array[size];
  for( int i = 0; i < size; i++){
    array[i] = data[i];
  }
  partition(array, size);
  data.clear();
  for( int i = 0; i < size; i++){
    data.push_back(array[i]);
  }
};

void heapSort(vector<int>& data){
  MaxHeap<int> heap;
  for(unsigned int i = 0; i < data.size(); i++){
    heap.push(data[i]);
  } 
  for(int i = data.size() - 1; i > -1 ; i--){
    data[i] = heap.top();
    heap.pop();
  }
};

void nonCompareSort(vector<int>& data){
  int max = 0;
  for(unsigned int i = 0; i < data.size(); i++){
    if(data[i] > max){
      max = data[i];
    }
  }
  int things[++max];
  for(int i = 0; i < max; i++){
    things[i] = 0;
  }
  for(unsigned int i = 0; i < data.size(); i++){
    things[data[i]] += 1;
  }
  vector<int> ret;
  for(int i = 0; i < max; i++){
    if(things[i]){
      for(int j = 0; j < things[i]; j++){
        ret.push_back(i);
      }
    }
  }
  data = ret;
};

vector<int> megerSort(vector<int>& left, vector<int>& right){
  if(left.size() > 1){
    vector<int> new_left;
    vector<int> new_right;
    for(unsigned int i = 0; i < left.size() / 2; i++){
      new_left.push_back(left[i]);
    }
    for(unsigned int i = left.size() / 2; i < left.size(); i++){
      new_right.push_back(left[i]);
    }
    left = megerSort(new_left, new_right);
  }
  if(right.size() > 1){
    vector<int> new_left;
    vector<int> new_right;
    for(unsigned int i = 0; i < right.size() / 2; i++){
      new_left.push_back(right[i]);
    }
    for(unsigned int i = right.size() / 2; i < right.size(); i++){
      new_right.push_back(right[i]);
    }
    right = megerSort(new_left, new_right);
  }
  vector<int> ret;
  int left_index = 0;
  int right_index = 0;
  int left_size = left.size();
  int right_size = right.size();
  while(left_index < left_size && right_index < right_size){
    if(left[left_index] < right[right_index]){
      ret.push_back(left[left_index++]);
    }else{
      ret.push_back(right[right_index++]);
    }
  }
  while(left_index < left_size){
    ret.push_back(left[left_index++]);
  }
  while(right_index < right_size){
    ret.push_back(right[right_index++]);
  }
  return ret;
}

#endif