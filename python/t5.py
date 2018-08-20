# -*- coding:utf-8 -*-

'''
剑指offer之面试题5：替换空格

题目：请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

思路：
见程序标注

编程环境：
Python2.7.12

作者：
CSDN博客：https://my.csdn.net/yeqiang19910412
Github：https://github.com/YeQiang1075736553

日期：
2018.8.20
'''

#-*- coding:utf-8 -*-

# class Solution:
#     # s 源字符串
#     def replaceSpace(self, s):
#         """直接使用Python字符串的内置函数（通过）"""
#         return s.replace(' ','%20')

###################################################################################################

class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        """
        剑指offer中的思路：（通过）
        step1：统计空格个数
        step2：计算替换后的字符串长度
        step：从字符串的后面开始复制和替换
        """
        if not isinstance(s,str) or len(s) <= 0 or s == None: # 判断非法输入
            return None

        original_length = len(s)

        space_num = 0
        for i in range(original_length): # 统计空格数
            if s[i] == ' ':
                space_num += 1

        new_str_length = original_length + space_num * 2
        new_str = new_str_length * [None]

        index_original = original_length - 1
        index_new = new_str_length -1

        while index_original >= 0 :
            if s[index_original] == ' ': # 有空格就插入
                new_str[index_new] = '0'
                new_str[index_new-1] = '2'
                new_str[index_new-2] = '%'
                index_original -= 1
                index_new -= 3
            else:
                new_str[index_new] = s[index_original]
                index_original -= 1
                index_new -= 1

        return ''.join(new_str)

if __name__ == "__main__":
    str1= "We Are Happy"
    solution = Solution()
    str2 = solution.replaceSpace(str1)
    print str2