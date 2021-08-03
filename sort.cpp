#include "sort.h"

template <class T>
void Sort<T>::BubbleSort() {
	LARGE_INTEGER t1, t2, tc;
	QueryPerformanceFrequency(&tc);
	QueryPerformanceCounter(&t1);

	int len = array.size();
	if (len < 2) return;
	int i = len - 1, j = 0, num = 0;
	for (; i > 0; --i) {
		num = i;
		for (j = 1; j <= i; ++j) {
			if (cmp(j - 1, j) > 0) {
				swap(array[j - 1], array[j]);
				num = j;
			}
		}
		i = num;
	}

	QueryPerformanceCounter(&t2);
	time = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;

	cout << "----------BubbleSort----------" << endl;
}

template <class T>
void Sort<T>::SelectSort() {
	LARGE_INTEGER t1, t2, tc;
	QueryPerformanceFrequency(&tc);
	QueryPerformanceCounter(&t1);

	int len = array.size();
	if (len < 2) return;
	int i = len - 1, j = 0, num = 0;
	for (; i > 0; --i) {
		for (j = 0; j <= i; ++j) {
			num = max(num, array[j]);
		}
		swap(array[i], num);
	}

	QueryPerformanceCounter(&t2);
	time = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;

	cout << "----------SelectSort----------" << endl;
}

template <class T>
void Sort<T>::HeapSort() {
	LARGE_INTEGER t1, t2, tc;
	QueryPerformanceFrequency(&tc);
	QueryPerformanceCounter(&t1);

	int len = array.size(), heaplen = array.size();
	if (len < 2) return;
	int i = len - 1, j = 0, num = 0;

	//建堆，这里我每个都是比较两次，交换两次（成立的时候），还有优化的空间;
	for (i = 1; i < len; ++i) {
		j = i;
		while (j > 0) {
			if (array[j] > array[(j - 1) / 2]) {
				swap(array[j], array[(j - 1) / 2]);
				j = (j - 1) / 2;
			}
			else break;
		}
	}
	//弹出最大值,并保持堆的特性
	i = len - 1;
	while (heaplen > 0) {
		swap(array[0], array[heaplen - 1]);
		--heaplen;
		j = 0;
		while (j < heaplen - 1) {
			if ((j + 1) * 2 < heaplen) {
				if (array[j * 2 + 1] > array[(j + 1) * 2]) {
					if (array[j] < array[j * 2 + 1]) {
						swap(array[j], array[j * 2 + 1]);
						j = j * 2 + 1;
					}
					else break;
				}
				else {
					if (array[j] < array[(j + 1) * 2]) {
						swap(array[j], array[(j + 1) * 2]);
						j = (j + 1) * 2;
					}
					else break;
				}
			}
			else if ((j + 1) * 2 == heaplen) {
				if (array[j] < array[j * 2 + 1]) {
					swap(array[j], array[j * 2 + 1]);
					j = j * 2 + 1;
				}
				else break;
			}
			else break;
		}
	}

	QueryPerformanceCounter(&t2);
	time = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;

	cout << "-----------HeapSort-----------" << endl;
}

template <class T>
void Sort<T>::InsertionSort() {

}

template <class T>
void Sort<T>::MergeSort() {

}

template <class T>
void Sort<T>::QuickSort() {

}

template <class T>
void Sort<T>::HillSort() {}

template <class T>
void Sort<T>::CountSort() {}

template <class T>
void Sort<T>::BaseSort() {}

template <class T>
void Sort<T>::BucketSort() {}

template <class T>
string Sort<T>::toString() {
	string ans = " result:";
	if (isCorrect()) ans += "true\t";
	else ans += "false\t";
	ans += "time:" + to_string(time) + "\n" + "==============================\n";

	return ans;
}

template <class T>
bool Sort<T>::isStable() {}

template <class T>
void Sort<T>::putout() {
	cout << toString() << endl;
	/*for (int i = 0; i < array.size(); ++i) {
		cout << array[i] << "_";
	}
	cout << endl << "=============================" << endl;*/
}

template <class T>
bool Sort<T>::isCorrect() {
	for (int i = 1; i < array.size(); ++i) {
		if (array[i - 1] > array[i]) return false;
	}
	return true;
}
