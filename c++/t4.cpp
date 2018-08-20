#include"iostream"
#include"vector"
using namespace std;

/*************************************************
剑指offer之面试题4：二位数组中的查找

题目：
在一个二维数组中，每一行都按照从左到右递增的顺序排序,每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

思路：
见程序标注

编程环境：
visual studio 2017

作者：
CSDN博客：https://my.csdn.net/yeqiang19910412
Github：https://github.com/YeQiang1075736553

日期：
2018.8.20
**************************************************/

//class Solution {
//public:
//	/**
//	* @brief 暴力解法
//	*
//	* @param target int 要查找的值
//	* @param array  vector<vector<int> > 二维数组
//	*
//	* @return bool 二维数组是否存在要查找的值
//	*
//	*/
//	bool Find(int target, vector<vector<int> > array) {
//		if(array.empty()){
//			return false;
//		}
//		for (int i=0; i < array.size(); ++i) {
//			for (int j=0; j < array[i].size(); ++j) {
//				if(target == array[i][j]){
//					return true;
//				}
//			}
//		}
//		return false;
//
//	}
//};

/////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
	/**
	* @brief 分治解-左下角
	* 查找方式从左下角开始查找，每次比较都可以剔除一列或者一行，从而加快速度完成查找
	*
	* 具体而言，假设选择的数字为 k，则有三种情况：
	* 1、target == k：此时直接返回即可
	* 2、target > k：剔除 k 所在的列（列号递增即可）
	* 3、target < k：剔除 k 所在的行（行号递减即可）
	*
	* @param target int 要查找的值
	* @param array  vector<vector<int> > 二维数组
	*
	* @return bool 二维数组是否存在要查找的值
	*
	*/
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty()) {
			return false;
		}

		int numberOfRow = array.size();
		int numberOfColumn = array[0].size();

		int row = numberOfRow - 1;
		int col = 0;

		while (row >= 0 && col <= numberOfColumn - 1) {
			if (target == array[row][col]) {
				return true;
			}
			else if (target > array[row][col]) {
				++col;
			}
			else {
				--row;
			}
		}
		return false;
	}
};

/////////////////////////////////////////////////////////////////////////////////////////////

//class Solution {
//public:
//	/**
//	* @brief 分治解-右上角
//	* 查找方式从右上角开始查找，每次比较都可以剔除一列或者一行，从而加快速度完成查找
//  *   
//  * 具体而言，假设选择的数字为 k，则有三种情况：
//  * 1、target == k：此时直接返回即可
//  * 2、target > k：剔除 k 所在的行（行号递增即可）
//  * 3、target < k：剔除 k 所在的列（列号递减即可）
//	*
//	* @param target int 要查找的值
//	* @param array  vector<vector<int> > 二维数组
//	*
//	* @return bool 二维数组是否存在要查找的值
//	*
//	*/
//	bool Find(int target, vector<vector<int> > array) {
//		if(array.empty()){
//			return false;
//		}
//
//		int numberOfRow = array.size();
//		int numberOfColumn = array[0].size();
//
//		int row = 0;
//		int col = numberOfColumn - 1;
//
//		while (row <= numberOfRow -1 && col >= 0) {
//			if (target == array[row][col]) {
//				return true;
//			}
//			else if (target > array[row][col]) {
//				++row;
//			}
//			else{
//				--col;
//			}
//		}
//		return false;
//	}
//};

/////////////////////////////////////////////////////////////////////////////////////////////

//class solution {
//public:
//	/**
//	* @brief 分治解-二分法
//	* 采用二分查找二维数组的每一行
//	*
//	* @param target int 要查找的值
//	* @param array  vector<vector<int> > 二维数组
//	*
//	* @return bool 二维数组是否存在要查找的值
//	*
//	*/
//	bool find(int target, vector<vector<int> > array) {
//		if(array.empty()){
//			return false;
//		}
//
//		int numberOfRow = array.size();
//		for (int i = 0; i < numberOfRow; ++i) {
//			if (binary_search(target,array[i])) {
//				return true;
//			}
//		}
//		return false;
//
//	}
//
//	bool binary_search(int target, vector<int> seq) {
//		int low = 0;
//		int high = seq.size()-1; 
//		int mid = 0;
//		while (low <= high) {
//			mid = low + (high - low) / 2;
//			if (seq[mid] > target) {
//				high = mid - 1;
//			}
//			else if (seq[mid] < target) {
//				low = mid + 1;
//			}
//			else {
//				return true;
//			}
//		}
//		return false;
//	}
//};

int main(void) {

	vector<vector<int> > arr = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
	int target = 10;
	Solution solution;
	bool result = solution.Find(target, arr);
	cout << result << endl;
	system("pause");
	return 0;
}