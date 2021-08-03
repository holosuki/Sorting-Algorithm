#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <windows.h>

using namespace std;

template <class T>
class Sort {
private:
	vector<T> array;
	double time;
public:
	Sort() {}
	Sort(vector<T> a):array(a) {}
	~Sort() {}

	//比较函数
	T cmp(int a, int b) { return array[a] - array[b]; }

	//测试耗时
	//double time();

	//输出
	string toString();

	//稳定性
	bool isStable();

	//输出array
	void putout();

	//判断正确性
	bool isCorrect();


	void BubbleSort();
	void SelectSort();
	void HeapSort();
	void InsertionSort();
	void MergeSort();
	void QuickSort();
	void HillSort();
	void CountSort();
	void BaseSort();
	void BucketSort();
};