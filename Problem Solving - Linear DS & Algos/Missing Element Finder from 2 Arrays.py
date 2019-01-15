"""
Program to find missing element from 2 arrays (lists)
"""


class TestFinder(object):
    def missingElementFinder(self, list1, list2):
        """
        From two lists, this function finds
        missing element
        For example: In [1,2,3,4] , [4,2,3]: 1 is missing.
        """
        list1.sort()
        list2.sort()
        for i in range(min(len(list1), len(list2))):
            if list1[i] != list2[i]:
                return list1[i]
        return list1[len(list1)-1]


list1 = input("Enter first array elements separated by a space: ").strip().split(" ")
list2 = input("Enter second array elements separated by a space: ").strip().split(" ")

t = TestFinder()
missingElement = t.missingElementFinder(list1, list2)
print(missingElement)
