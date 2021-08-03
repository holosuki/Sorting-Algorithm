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
	void MergeSort();
	void QuickSort();
	void HillSort();
	void CountSort();
	void BaseSort();
	void BucketSort();
};