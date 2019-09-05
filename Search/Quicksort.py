# -*- coding: utf-8 -*-

"""
    정렬 알고리즘 중 가장 빠른 성능을 가지고 있는 알고리즘 입니다.
    최선 : O(n log n)시간 복잡도를 가지고 있습니다.
    최악  O(n^2) 복잡도 발생
"""


def quick_sort(arr):

    # 정렬할게 없는경우.
    if len(arr) <= 1:
        return arr

    # 기준점
    pivot = arr[0]

    less = [element for element in arr[1:] if pivot > element]
    high = [element for element in arr[1:] if pivot <= element]

    return quick_sort(less) + [pivot] + quick_sort(high)


test_list = [5, 6, 3, 2, 8, 7, 1]
print(quick_sort(test_list))
print(quick_sort([3, 1]))
