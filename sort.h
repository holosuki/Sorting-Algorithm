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

	//�ȽϺ���
	T cmp(int a, int b) { return array[a] - array[b]; }

	//���Ժ�ʱ
	//double time();

	//���
	string toString();

	//�ȶ���
	bool isStable();

	//���array
	void putout();

	//�ж���ȷ��
	bool isCorrect();


	void BubbleSort();
	void SelectSort();
	void HeapSort();
	void InsertionSort();

	void merge(int left, int right, vector<T>& array_merge);
	void MergeSort();

	void quick(int left, int right);
	void QuickSort();

	void insertionsort(int begin, int step);
	void HillSort();

	void CountSort();
	void BaseSort();
	void BucketSort();
};