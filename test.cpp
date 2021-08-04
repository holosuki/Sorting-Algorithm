#include "sort.h"
#include "sort.cpp"
#include <cstdlib>
#include <ctime>

vector<int> randomArray(int k, int n) {
	vector<int> ans(k);
	srand((int)time(0));  // 产生随机种子  把0换成NULL也行
	for (int i = 0; i < k; i++)
	{
		ans[i] = rand() % n;
	}
	return ans;
}

int main() {
	vector<int> array1 = randomArray(1000, 1000);
	vector<int> array2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	Sort<int> test_1(array1);
	test_1.BubbleSort();
	test_1.putout();

	//vector<int> array2 = array1;
	Sort<int> test_2(array1);
	test_2.SelectSort();
	test_2.putout();

	//vector<int> array3 = array1;
	Sort<int> test_3(array1);
	test_3.HeapSort();
	test_3.putout();

	//vector<int> array4 = array1;
	Sort<int> test_4(array1);
	test_4.InsertionSort();
	test_4.putout();

	Sort<int> test_5(array1);
	test_5.MergeSort();
	test_5.putout();

	Sort<int> test_6(array1);
	test_6.QuickSort();
	test_6.putout();

	Sort<int> test_7(array1);
	test_7.HillSort();
	test_7.putout();

	return 0;
}