#include"iostream"
#include"vector"
using namespace std;

/*************************************************
��ָoffer֮������4����λ�����еĲ���

��Ŀ��
��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������,ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������

˼·��
�������ע

��̻�����
visual studio 2017

���ߣ�
CSDN���ͣ�https://my.csdn.net/yeqiang19910412
Github��https://github.com/YeQiang1075736553

���ڣ�
2018.8.20
**************************************************/

//class Solution {
//public:
//	/**
//	* @brief �����ⷨ
//	*
//	* @param target int Ҫ���ҵ�ֵ
//	* @param array  vector<vector<int> > ��ά����
//	*
//	* @return bool ��ά�����Ƿ����Ҫ���ҵ�ֵ
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
	* @brief ���ν�-���½�
	* ���ҷ�ʽ�����½ǿ�ʼ���ң�ÿ�αȽ϶������޳�һ�л���һ�У��Ӷ��ӿ��ٶ���ɲ���
	*
	* ������ԣ�����ѡ�������Ϊ k���������������
	* 1��target == k����ʱֱ�ӷ��ؼ���
	* 2��target > k���޳� k ���ڵ��У��кŵ������ɣ�
	* 3��target < k���޳� k ���ڵ��У��кŵݼ����ɣ�
	*
	* @param target int Ҫ���ҵ�ֵ
	* @param array  vector<vector<int> > ��ά����
	*
	* @return bool ��ά�����Ƿ����Ҫ���ҵ�ֵ
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
//	* @brief ���ν�-���Ͻ�
//	* ���ҷ�ʽ�����Ͻǿ�ʼ���ң�ÿ�αȽ϶������޳�һ�л���һ�У��Ӷ��ӿ��ٶ���ɲ���
//  *   
//  * ������ԣ�����ѡ�������Ϊ k���������������
//  * 1��target == k����ʱֱ�ӷ��ؼ���
//  * 2��target > k���޳� k ���ڵ��У��кŵ������ɣ�
//  * 3��target < k���޳� k ���ڵ��У��кŵݼ����ɣ�
//	*
//	* @param target int Ҫ���ҵ�ֵ
//	* @param array  vector<vector<int> > ��ά����
//	*
//	* @return bool ��ά�����Ƿ����Ҫ���ҵ�ֵ
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
//	* @brief ���ν�-���ַ�
//	* ���ö��ֲ��Ҷ�ά�����ÿһ��
//	*
//	* @param target int Ҫ���ҵ�ֵ
//	* @param array  vector<vector<int> > ��ά����
//	*
//	* @return bool ��ά�����Ƿ����Ҫ���ҵ�ֵ
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