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
	LARGE_INTEGER t1, t2, tc;
	QueryPerformanceFrequency(&tc);
	QueryPerformanceCounter(&t1);

	int len = array.size();
	if (len < 2) return;
	int i = 1, j = 0, num = 0;
	for (; i < len; ++i) {
		num = array[i];
		for (j = i - 1; j >= 0; --j) {
			if (num >= array[j]) { 
				array[j + 1] = num; 
				break; 
			}
			else {
				array[j + 1] = array[j];
				if (j == 0) array[j] = num;
			}
		}
	}

	QueryPerformanceCounter(&t2);
	time = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;

	cout << "---------InsertionSort--------" << endl;
}

template <class T>
void Sort<T>::MergeSort() {
	LARGE_INTEGER t1, t2, tc;
	QueryPerformanceFrequency(&tc);
	QueryPerformanceCounter(&t1);

	int len = array.size();
	if (len < 2) return;
	vector<T> array_merge(len / 2 + 1);
	merge(0, len, array_merge);

	QueryPerformanceCounter(&t2);
	time = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;

	cout << "-----------MergeSort----------" << endl;
}

template <class T>
void Sort<T>::merge(int left, int right, vector<T> &array_merge) {
	if (left == right - 1) return;
	int mid = (left + right) / 2;
	merge(left, mid, array_merge);
	merge(mid, right, array_merge);
	int i = left, l = left, r = mid;
	for (; i < mid; ++i) {
		array_merge[i - left] = array[i];
	}
	for (i = left; i < right; ++i) {
		if (l >= mid && r < right) {
			array[i] = array[r];
			++r;
			continue;
		}
		if(l < mid && r >= right) {
			array[i] = array_merge[l - left];
			++l;
			continue;
		}
		if (array_merge[l - left] <= array[r]) {
			array[i] = array_merge[l - left];
			++l;
		}
		else {
			array[i] = array[r];
			++r;
		}
	}
}

template <class T>
void Sort<T>::QuickSort() {
	LARGE_INTEGER t1, t2, tc;
	QueryPerformanceFrequency(&tc);
	QueryPerformanceCounter(&t1);

	int len = array.size();
	if (len < 2) return;
	quick(0, len);

	QueryPerformanceCounter(&t2);
	time = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;

	cout << "-----------QuickSort----------" << endl;
}

template <class T>
void Sort<T>::quick(int left, int right) {
	if (right - left <= 1) return;
	int mid = (left + right) / 2;
	int num = array[mid];//任取轴点元素，一般来说随机抽取比较好一点
	int begin = left, end = right - 1, now = 0;
	swap(array[mid], array[begin]);
	while (begin != end) {
		if (now == 0) {
			if (array[end] > num) --end;
			else {
				array[begin++] = array[end];
				now = 1;
			}
		}
		else {
			if (array[begin] <= num) ++begin;
			else {
				array[end--] = array[begin];
				now = 0;
			}
		}
	}
	array[begin] = num;
	quick(left, begin);
	quick(begin, right);
}

template <class T>
void Sort<T>::HillSort() {
	LARGE_INTEGER t1, t2, tc;
	QueryPerformanceFrequency(&tc);
	QueryPerformanceCounter(&t1);

	int len = array.size();
	if (len < 2) return;
	vector<int> step;
	int num = 1, i = 1;
	while (num < len) {
		step.push_back(num);
		if (i % 2 == 0) num = 9 * (((int)pow(2, i)) - ((int)pow(2, i / 2))) + 1;
		else num = 8 * ((int)pow(2, i)) - 6 * ((int)pow(2, (i + 1) / 2)) + 1;
		++i;
	}
	for(num = step.size() - 1; num >= 0; --num) {
		for (i = 0; i < step[num]; ++i) {
			insertionsort(i, step[num]);
		}
	}

	QueryPerformanceCounter(&t2);
	time = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;

	cout << "-----------HillSort-----------" << endl;
}

template <class T>
void Sort<T>::insertionsort(int begin, int step) {
	int i = begin + step, j = 0, num = 0;
	for (; i < array.size(); i += step) {
		num = array[i];
		for (j = i - step; j >= 0; j -= step) {
			if (num >= array[j]) {
				array[j + step] = num;
				break;
			}
			else {
				array[j + step] = array[j];
				if (j == 0) array[j] = num;
			}
		}
	}
}

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
