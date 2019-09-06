# -*- coding: utf-8 -*-
"""
    이진트리

       10
    3     12
  2  4  11 13

왼쪽은 부모노드 값보다 작은 값을
오른쪽은 부모노드 값보다 큰 값을
"""


class Node(object):
    def __init__(self, data):
        self.data = data
        self.left = self.right = None


class BinaryTree(object):
    def __init__(self):
        self.root = None

    def insert(self, data):

        self.root = self.insert_value(self.root, data)

    def insert_value(self, node, data):

        if node is None:
            node = Node(data)
        else:
            if node.data >= data:
                node.left = self.insert_value(node.left, data)
            else:
                node.right = self.insert_value(node.right, data)

        return node

    def find(self, target):

        return self.finds(self.root, target)

    def finds(self, node, target):
        print(node.data)
        if node.data == target or node is None:
            return node is not None

        elif node.data >= target:
            return self.finds(node.left, target)
        else:
            return self.finds(node.right, target)


arr = [10, 2, 3, 4, 1, 11, 12, 13]
bt = BinaryTree()
for i in arr:
    bt.insert(i)

print(bt.find(3))
