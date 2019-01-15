"""
Singly List Implementation example in Python 3
Written by: Muhammad Hasnain Naeem
Dated: 8/20/2018
"""

class Node:
    def __init__(self, value):
        self.value = value
        self.nextNode = None


a = Node(0)
b = Node(1)
c = Node(2)
d = Node(3)

a.nextNode = b
b.nextNode = c
c.nextNode = d

linkedList = a

print(linkedList.nextNode.nextNode.nextNode.value)
