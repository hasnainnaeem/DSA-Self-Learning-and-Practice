import ctypes


class DynamicArray (object):
    """
    Dynamic Array Class to store "object" type elements.
    """

    def __init__(self,capacity=1):
        self.capacity = capacity
        self.length = 0  # current elements
        self.array = self.make_array(self.capacity)

    def make_array(self, capacity=1):
        return (capacity * ctypes.py_object)()

    def __len__(self):
        """
        Returns number of elements in array
        """
        return self.length

    def append(self, element):
        """
        Adds an element at the end of array
        """
        if self.length == self.capacity:
            self._resize(2*self.capacity)

        self.array[self.length] = element
        self.length += 1

    def _resize(self, new_capacity):
        """
        Changes capacity of "array" instance variable
        """
        new_array = self.make_array(new_capacity)  # New array of desired capacity

        for i in range(0, self.length):  # Copying elements of "array" in "new_array"
            new_array[i] = self.array[i]

        self.array = new_array  # Assigning reference of "new_array" to "array" variable
        self.capacity = new_capacity

    def __getitem__(self,index):
        if not 0 <= index and index < self.length:
            return IndexError("Given index is out of bounds!")
        else:
            return self.array[index]


class TestingDynamicArray:

    array = DynamicArray()  # No capacity is passed, default capacity is 1
    array.append(100)
    print((array[0]))
    array.append(1)
    print(array[1])