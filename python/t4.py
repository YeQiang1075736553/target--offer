# -*- coding:utf-8 -*-

'''
剑指offer之面试题4：二位数组中的查找

题目：
在一个二维数组中，每一行都按照从左到右递增的顺序排序,每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

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

class Solution:
    # array 二维列表
    def Find(self, target, array):
        """查找方式从左下角开始查找，每次比较都可以剔除一列或者一行，从而加快速度完成查找

        具体而言，假设选择的数字为 k，则有三种情况：
        1、target == k：此时直接返回即可
        2、target > k：剔除 k 所在的列（列号递增即可）
        3、target < k：剔除 k 所在的行（行号递减即可）

        参数：
        ----------
        :param target: int
            要查找的值
        :param array: [[]]
            二维数组

        返回值
        ----------
        :return: bool
            二维数组是否存在要查找的值

        示例
        ----------
        array = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
        target = 71
        solution = Solution()
        is_exist = solution.Find(target,array)
        print is_exist
        """
        # 如果数组为空
        if not array:
            return False

        num_row = len(array)
        num_col = len(array[0])

        # 左下角开始
        row = num_row-1
        col = 0
        while row >= 0 and col <= num_col-1:
            if target == array[row][col]:
                return True
            elif target > array[row][col]:
                col += 1
            else:
                row -= 1
        return False

###################################################################################################

'''
class Solution:
    # array 二维列表
    def Find(self, target, array):
        """查找方式从右上角开始查找，每次比较都可以剔除一列或者一行，从而加快速度完成查找
        
        具体而言，假设选择的数字为 k，则有三种情况：
        1、target == k：此时直接返回即可
        2、target > k：剔除 k 所在的行（行号递增即可）
        3、target < k：剔除 k 所在的列（列号递减即可）
        
        """
        # 如果数组为空
        if not array:
            return False

        num_row = len(array)
        num_col = len(array[0])

        # 右上角开始查找
        row = 0
        col = num_col-1
        while row <= num_row-1 and col >=0:
            if  target == array[row][col]:
                return True
            elif target > array[row][col]:
                row += 1
            else:
                col -= 1
        return False
'''

###################################################################################################

'''
class Solution:
    # array 二维列表
    def Find(self, target, array):
        """
        借助二分查找，可以在 O(nlogn) 的时间复杂度内完成查找
        """
        # 如果数组为空
        if not array:
            return False

        for row in array:
            if self.binary_search(row,target):
                return True

        return False

    def binary_search(self,seq,target):
        # 如果该行为空
        if not seq:
            return False

        low = 0
        high = len(seq)-1
        while low <= high:
            mid = low + (high - low)//2
            if seq[mid] > target:
                high = mid - 1
            elif seq[mid] < target:
                low =  mid + 1
            else:
                return True
            
        return False
'''

if __name__ == "__main__":
    array = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    target = 7
    solution = Solution()
    is_exist = solution.Find(target,array)
    print is_exist