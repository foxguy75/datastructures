#ifndef SORT_TEST_H
#define SORT_TEST_H

#include "MySort.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cxxtest/TestSuite.h>

using namespace std;

class SortTest : public CxxTest::TestSuite {
public:
  void (*f)(vector<int>& list);

  void setUp(){
    
  }
  
  void testisSelectionSortedEmpty() {
    vector<int> empty;
    selectionSort(empty);
    TS_ASSERT_EQUALS(isSorted(empty),true);
  }
  
  void testisBubbleSortedEmpty() {
    vector<int> empty;
    bubbleSort(empty);
    TS_ASSERT_EQUALS(isSorted(empty),true);
  }
  
  void testisMergeSortedEmpty() {
    vector<int> empty;
    mergeSort(empty);
    TS_ASSERT_EQUALS(isSorted(empty),true);
  }
  
  void testisMerge2SortedEmpty() {
    vector<int> empty;
    mergeSort2(empty);
    TS_ASSERT_EQUALS(isSorted(empty),true);
  }
  
  void testisQuickSortedEmpty() {
    vector<int> empty;
    quickSort(empty);
    TS_ASSERT_EQUALS(isSorted(empty),true);
  }
  
  void testisHeapSortedEmpty() {
    vector<int> empty;
    heapSort(empty);
    TS_ASSERT_EQUALS(isSorted(empty),true);
  }
  
  void testisNonCompareSortedEmpty() {
    vector<int> empty;
    nonCompareSort(empty);
    TS_ASSERT_EQUALS(isSorted(empty),true);
  }
  
  void testisSelectionSortedTwoElements() {
    srand((unsigned int)time(0));
    vector<int> a;
    a.push_back(rand() % 1000);
    a.push_back(rand() % 1000);
    selectionSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisBubbleSortedTwoElements() {
    srand((unsigned int)time(0));
    vector<int> a;
    a.push_back(rand() % 1000);
    a.push_back(rand() % 1000);
    bubbleSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisMergeSortedTwoElements() {
    srand((unsigned int)time(0));
    vector<int> a;
    a.push_back(rand() % 1000);
    a.push_back(rand() % 1000);
    mergeSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisMerge2SortedTwoElements() {
    srand((unsigned int)time(0));
    vector<int> a;
    a.push_back(rand() % 1000);
    a.push_back(rand() % 1000);
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisQuickSortedTwoElements() {
    srand((unsigned int)time(0));
    vector<int> a;
    a.push_back(rand() % 1000);
    a.push_back(rand() % 1000);
    quickSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisHeapSortedTwoElements() {
    srand((unsigned int)time(0));
    vector<int> a;
    a.push_back(rand() % 1000);
    a.push_back(rand() % 1000);
    heapSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisNonCompareSortedTwoElements() {
    srand((unsigned int)time(0));
    vector<int> a;
    a.push_back(rand() % 1000);
    a.push_back(rand() % 1000);
    nonCompareSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisSelectionSortedSameElements() {
    vector<int> a;
    a.push_back(3);
    a.push_back(3);
    a.push_back(3);
    selectionSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisBubbleSortedSameElements() {
    vector<int> a;
    a.push_back(3);
    a.push_back(3);
    a.push_back(3);
    bubbleSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisMergeSortedSameElements() {
    vector<int> a;
    a.push_back(3);
    a.push_back(3);
    a.push_back(3);
    mergeSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisMerge2SortedSameElements() {
    vector<int> a;
    a.push_back(3);
    a.push_back(3);
    a.push_back(3);
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisQuickSortedSameElements() {
    vector<int> a;
    a.push_back(3);
    a.push_back(3);
    a.push_back(3);
    quickSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisHeapSortedSameElements() {
    vector<int> a;
    a.push_back(3);
    a.push_back(3);
    a.push_back(3);
    heapSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisNonCompareSortedSameElements() {
    vector<int> a;
    a.push_back(3);
    a.push_back(3);
    a.push_back(3);
    nonCompareSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisSelectionSortedBackwardsElements() {
    vector<int> a;
    for(unsigned int i = 20; i > 0; i--){
      a.push_back(i);
    }
    selectionSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisBubbleSortedBackwardsElements() {
    vector<int> a;
    for(unsigned int i = 20; i > 0; i--){
      a.push_back(i);
    }
    bubbleSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisMergeSortedBackwardsElements() {
    vector<int> a;
    for(unsigned int i = 20; i > 0; i--){
      a.push_back(i);
    }
    mergeSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisMerge2SortedBackwardsElements() {
    vector<int> a;
    for(unsigned int i = 20; i > 0; i--){
      a.push_back(i);
    }
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisQuickSortedBackwardsElements() {
    vector<int> a;
    for(unsigned int i = 20; i > 0; i--){
      a.push_back(i);
    }
    quickSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisHeapSortedBackwardsElements() {
    vector<int> a;
    for(unsigned int i = 20; i > 0; i--){
      a.push_back(i);
    }
    heapSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisNonCompareSortedBackwardsElements() {
    vector<int> a;
    for(unsigned int i = 20; i > 0; i--){
      a.push_back(i);
    }
    nonCompareSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisSelectionSortedRandomElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 20; i++){
      a.push_back(i % 1000);
    }
    selectionSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisBubbleSortedRandomElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 20; i++){
      a.push_back(i % 1000);
    }
    bubbleSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisMergeSortedRandomElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 20; i++){
      a.push_back(i % 1000);
    }
    mergeSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisMerge2SortedRandomElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 20; i++){
      a.push_back(i % 1000);
    }
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisQuickSortedRandomElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 20; i++){
      a.push_back(i % 1000);
    }
    quickSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisHeapSortedRandomElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 20; i++){
      a.push_back(i % 1000);
    }
    heapSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  void testisNonCompareSortedRandomElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 20; i++){
      a.push_back(i % 1000);
    }
    nonCompareSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisSelectionSortedInOrderElements() {
    vector<int> a;
    for(unsigned int i = 0; i < 20; i++){
      a.push_back(i);
    }
    selectionSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisBubbleSortedInOrderElements() {
    vector<int> a;
    for(unsigned int i = 0; i < 20; i++){
      a.push_back(i);
    }
    bubbleSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisMergeSortedInOrderElements() {
    vector<int> a;
    for(unsigned int i = 0; i < 20; i++){
      a.push_back(i);
    }
    mergeSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisMerge2SortedInOrderElements() {
    vector<int> a;
    for(unsigned int i = 0; i < 20; i++){
      a.push_back(i);
    }
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisQuickSortedInOrderElements() {
    vector<int> a;
    for(unsigned int i = 0; i < 20; i++){
      a.push_back(i);
    }
    quickSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisHeapSortedInOrderElements() {
    vector<int> a;
    for(unsigned int i = 0; i < 20; i++){
      a.push_back(i);
    }
    heapSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisNonCompareSortedInOrderElements() {
    vector<int> a;
    for(unsigned int i = 0; i < 20; i++){
      a.push_back(i);
    }
    nonCompareSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisSelectionSortedLotsElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 1000; i++){
      a.push_back(i % 1000);
    }
    selectionSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisBubbleSortedLotsElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 1000; i++){
      a.push_back(i % 1000);
    }
    bubbleSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisMergeSortedLotsElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 1000; i++){
      a.push_back(i % 1000);
    }
    mergeSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisMerge2SortedLotsElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 1000; i++){
      a.push_back(i % 1000);
    }
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisQuickSortedLotsElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 1000; i++){
      a.push_back(i % 1000);
    }
    quickSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisHeapSortedLotsElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 1000; i++){
      a.push_back(i % 1000);
    }
    heapSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisNonCompareSortedLotsElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 1000; i++){
      a.push_back(i % 1000);
    }
    nonCompareSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisSelectionSortedRandomPlace2Elements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 100; i++){
      a.push_back(rand() % 2);
    }
    selectionSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisBubbleSortedRandomPlace2Elements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 100; i++){
      a.push_back(rand() % 2);
    }
    bubbleSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisMergeSortedRandomPlace2Elements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 100; i++){
      a.push_back(rand() % 2);
    }
    mergeSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisMerge2SortedRandomPlace2Elements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 100; i++){
      a.push_back(rand() % 2);
    }
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisQuickSortedRandomPlace2Elements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 100; i++){
      a.push_back(rand() % 2);
    }
    quickSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisHeapSortedRandomPlace2Elements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 100; i++){
      a.push_back(rand() % 2);
    }
    heapSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisNonCompareSortedRandomPlace2Elements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 100; i++){
      a.push_back(rand() % 2);
    }
    nonCompareSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisSelectionSortedOneElements() {
    vector<int> a;
    a.push_back(5);
    selectionSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisBubbleSortedOneElements() {
    vector<int> a;
    a.push_back(5);
    bubbleSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisMergeSortedOneElements() {
    vector<int> a;
    a.push_back(5);
    mergeSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisMerge2SortedOneElements() {
    vector<int> a;
    a.push_back(5);
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisQuickSortedOneElements() {
    vector<int> a;
    a.push_back(5);
    quickSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisHeapSortedOneElements() {
    vector<int> a;
    a.push_back(5);
    heapSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisNonCompareSortedOneElements() {
    vector<int> a;
    a.push_back(5);
    nonCompareSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisSelectionSortedHalfandHalfElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 50; i++){
      a.push_back(i);
    }
    for(unsigned int i = 0; i < 50; i++){
      a.push_back(rand() % 100);
    }
    selectionSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisBubbleSortedHalfandHalfElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 50; i++){
      a.push_back(i);
    }
    for(unsigned int i = 0; i < 50; i++){
      a.push_back(rand() % 100);
    }
    bubbleSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisMergeSortedHalfandHalfElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 50; i++){
      a.push_back(i);
    }
    for(unsigned int i = 0; i < 50; i++){
      a.push_back(rand() % 100);
    }
    mergeSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisMerge2SortedHalfandHalfElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 50; i++){
      a.push_back(i);
    }
    for(unsigned int i = 0; i < 50; i++){
      a.push_back(rand() % 100);
    }
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisQuickSortedHalfandHalfElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 50; i++){
      a.push_back(i);
    }
    for(unsigned int i = 0; i < 50; i++){
      a.push_back(rand() % 100);
    }
    quickSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisHeapSortedHalfandHalfElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 50; i++){
      a.push_back(i);
    }
    for(unsigned int i = 0; i < 50; i++){
      a.push_back(rand() % 100);
    }
    heapSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }
  
  void testisNonCompareSortedHalfandHalfElements() {
    vector<int> a;
    srand((unsigned int)time(0));
    for(unsigned int i = 0; i < 50; i++){
      a.push_back(i);
    }
    for(unsigned int i = 0; i < 50; i++){
      a.push_back(rand() % 100);
    }
    nonCompareSort(a);
    TS_ASSERT_EQUALS(isSorted(a),true);
  }

  
};

#endif
