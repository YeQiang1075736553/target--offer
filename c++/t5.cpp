#include"iostream"
using namespace std;

/*************************************************
��ָoffer֮������5���滻�ո�

��Ŀ����ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��


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

class Solution {
public:
	void replaceSpace(char *str, int length) {
		/**
		* @brief ��ָoffer�е�˼·��
		* step1��ͳ�ƿո����
		* step2�������滻����ַ�������
		* step�����ַ����ĺ��濪ʼ���ƺ��滻

		* @param *str char �ַ���
		* @param length  int �ַ����ĳ���
		*
		* @return char ���ز������ַ���
		*
		*/
		if (str == nullptr && length <= 0) {
			return;
		}

		int originalLength = 0; 
		int numberOfBlack = 0;

		// ͳ�ƿո���
		int i = 0;
		while (str[i] != '\0') {
			++originalLength; // ������'\0'
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
//		// ��ָofferԴ����
//		if (str == nullptr && length <= 0)
//			return;
//
//		/*originalLength Ϊ�ַ���str��ʵ�ʳ���*/
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
//		/*newLength Ϊ�ѿո��滻��'%20'֮��ĳ���*/
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
	int length = sizeof(str) / sizeof(str[0]) ; // ����'\0'
	Solution solution;
	solution.replaceSpace(str, length);
	cout << str << endl;
	system("pause");
	return 0;
}