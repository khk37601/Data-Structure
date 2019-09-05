# -*- coding: utf-8 -*-
"""
    ** 이진 탐색 **

     이진 탐색은 탐색의 대상이 오름차순으로 정렬되었다는 전제조건으로 시작한다.
"""

# 재귀적


def binary_search2(number, start, end, target):

    mid = (start + end) // 2

    if start <= end:
        return -1

    if number[mid] == target:
        return mid

    if number[mid] > target:
        return binary_search2(number, start, mid - 1, target)
    elif number[mid] < target:
        return binary_search2(number, mid + 1, end, target)


# 반복문
def binary_search(number, start, end, target):

    list_s = sorted(number)

    while start <= end:

        mid = (start + end) // 2

        if list_s[mid] == target:
            return mid

        if target < list_s[mid]:
            end = mid - 1
        elif target > list_s[mid]:
            start = mid + 1

    else:
        return -1


# if __name__ == __main__:

number_list = [5, 1, 3, 4, 6, 8, 7]
lists = sorted(number_list)

index = binary_search(number_list, 0, len(number_list) - 1, 3)
index2 = binary_search2(lists, 0, len(number_list) - 1, 2)
print(index, index2)
