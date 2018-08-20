#include"iostream"
using namespace std;

/*************************************************
剑指offer之面试题5：替换空格

题目：请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。


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

class Solution {
public:
	void replaceSpace(char *str, int length) {
		/**
		* @brief 剑指offer中的思路：
		* step1：统计空格个数
		* step2：计算替换后的字符串长度
		* step：从字符串的后面开始复制和替换

		* @param *str char 字符串
		* @param length  int 字符串的长度
		*
		* @return char 返回插入后的字符串
		*
		*/
		if (str == nullptr && length <= 0) {
			return;
		}

		int originalLength = 0; 
		int numberOfBlack = 0;

		// 统计空格数
		int i = 0;
		while (str[i] != '\0') {
			++originalLength; // 不包括'\0'
			if (str[i] == ' ') {
				++numberOfBlack;
			}
			++i;
		}

		int indexOfOriginal = originalLength; // indexOfOriginal = 13
		int indexOfNew = originalLength + numberOfBlack * 2; // indexOfNew = 17

		cout << indexOfNew << endl;
		cout << indexOfOriginal << endl;

		while (indexOfOriginal>=0)
		{
			if (str[indexOfOriginal] == ' ') {
				str[indexOfNew] = '0';
				str[indexOfNew-1] = '2';
				str[indexOfNew-2] = '%';
				indexOfNew -= 3;
				indexOfOriginal -= 1;
			}
			else {
				str[indexOfNew] = str[indexOfOriginal];
				indexOfNew -= 1;
				indexOfOriginal -= 1;
			}
		}
	}
};

/////////////////////////////////////////////////////////////////////////////////////////////

//class Solution {
//public:
//	void replaceSpace(char *str, int length)
//	{
//		// 剑指offer源代码
//		if (str == nullptr && length <= 0)
//			return;
//
//		/*originalLength 为字符串str的实际长度*/
//		int originalLength = 0;
//		int numberOfBlank = 0;
//		int i = 0;
//		while (str[i] != '\0')
//		{
//			++originalLength;
//
//			if (str[i] == ' ')
//				++numberOfBlank;
//
//			++i;
//		}
//		/*newLength 为把空格替换成'%20'之后的长度*/
//		int newLength = originalLength + numberOfBlank * 2;
//		int indexOfOriginal = originalLength;
//		int indexOfNew = newLength;
//		cout << indexOfNew << endl;
//		cout << indexOfOriginal << endl;
//		while (indexOfOriginal >= 0)
//		{
//			if (str[indexOfOriginal] == ' ')
//			{
//				str[indexOfNew--] = '0';
//				str[indexOfNew--] = '2';
//				str[indexOfNew--] = '%';
//			}
//			else
//			{
//				str[indexOfNew--] = str[indexOfOriginal];
//			}
//
//			--indexOfOriginal;
//		}
//	}
//};


int main(void) {
	char str[] = "We Are Happy.";
	int length = sizeof(str) / sizeof(str[0]) ; // 包括'\0'
	Solution solution;
	solution.replaceSpace(str, length);
	cout << str << endl;
	system("pause");
	return 0;
}