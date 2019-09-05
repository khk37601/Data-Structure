# -*- coding: utf-8 -*-

"""
    정렬 알고리즘중 가장 간단하고 직관적인 알고리즘.
    최악 O(n^2)시간 복잡도가 발생 합니다.

"""


def bubble_bubble(arr):

    for loop in range(len(arr)-1):
        for loop2 in range(len(arr)-loop-1):
            if arr[loop2] > arr[loop2+1]:

                """
                    tmp = arr[loop2]
                    arr[loop2] = arr[loop2+1]
                    arr[loop2+1] = tmp
                """
                arr[loop2], arr[loop2+1] = arr[loop2+1], arr[loop2]

    return arr


print(bubble_bubble([5, 1, 3, 4, 6, 8, 7]))
