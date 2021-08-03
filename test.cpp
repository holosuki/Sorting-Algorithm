#include "sort.h"
#include "sort.cpp"
#include <cstdlib>
#include <ctime>

vector<int> randomArray(int k) {
	vector<int> ans(k);
	srand((int)time(0));  // 产生随机种子  把0换成NULL也行
	for (int i = 0; i < k; i++)
	{
		ans[i] = rand() % 10000;
	}
	return ans;
}

int main() {
	vector<int> array1 = randomArray(10000);
	Sort<int> test_1(array1);
	test_1.BubbleSort();
	test_1.putout();

	vector<int> array2 = array1;
	Sort<int> test_2(array2);
	test_2.SelectSort();
	test_2.putout();

	vector<int> array3 = array1;
	Sort<int> test_3(array3);
	test_3.HeapSort();
	test_3.putout();

	/*vector<int> array4 = { 10, 5, 31, 26, 41, 89, 51, 26, 13, 69 };
	Sort<int> test_4(array4);
	test_4.HeapSort();
	test_4.putout();*/

	return 0;
}