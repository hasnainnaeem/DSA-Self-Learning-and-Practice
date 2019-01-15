"""
Binary Search Implementation Using Strings
Written by: Hasnain Naeem
Date: 8/16/2018
"""


def binarySearch(dataList, toFind):
    size = len(dataList)
    if size == 0:
        return None

    high = size - 1
    low = 0
    while low <= high:
        mid = (low + high) // 2
        if dataList[mid] == toFind:
            return mid
        elif dataList[mid] > toFind:
            high = mid - 1
        else:
            low = mid + 1


names = [
    "Maryetta Leyden",
    "Waltraud Bainbridge",
    "Florrie Ko",
    "Melaine Sandor",
    "Marla Fagan",
    "Cecile Strickland",
    "Nicole Mak",
    "Neely Poff",
    "Ward Singletary",
    "Susanne Boehman",
    "Narcisa Real",
    "Viola Perreira",
    "Pat Godin",
    "Lexie Demma",
    "Kandace Peper",
    "Casey Sambrano",
    "Cornelius Poulson"
]

names.sort()

toFind = input("Enter name to be searched: ")
index = binarySearch(names, toFind)

if index == None:
    print("Name not found.")

else:
    print(names[index]+" is located at index: "+str(index))