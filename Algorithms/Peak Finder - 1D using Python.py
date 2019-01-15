""" 1-D Peak Finding Algorithm 
    Dated: 7/1/2018 """


def peakFinder(data):  # list of numbers

    size = len(data)
    mid = size // 2

    #if first element in list then we only need to check conditions by comparing with next element
    #if last element (size -1) then we only need to check conditions by comparing with second last element
    
    if (mid == 0 or data[mid] >= data[mid - 1]) and (mid == size - 1 or data[mid] >= data[mid + 1]):   # Checking if middle element is peak
        return data[mid]

    elif mid > 0 and data[mid] <= data[mid - 1]:    # If on left side there is greater element check there
        return peakFinder(data[0:mid])    #Using recursion to find find peak element in left side of list

    elif mid > size - 1 and data[mid] <= data[mid + 1]:    # If  on right side there is greater element check there
        return peakFinder(data[mid + 1:size - 1])


n = int(input("Enter number of elements: "))
data = []
for i in range(0,n):
    data.append(int(input("Enter element " + str(i + 1)+" : ")))

print("Peak is: " + str(peakFinder(data)))
