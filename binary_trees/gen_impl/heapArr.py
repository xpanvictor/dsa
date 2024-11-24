import math


h = [20, 10, 15, 8, 7, 13, 14, 2, 5, 6]
H2 = [2, 8, 6, 1, 10, 15, 3, 12, 11]

class HeapArr:
    """
    heap[i] >= heap[2i + 1]
    heap[i] >= heap[2i + 2]
    """
    heapArr = []
    def __init__(self, arr: list):
        # use Floyd algorithm to create heap using bottom top 
        self.heapArr = self.FloydAlgorithm(arr.copy())

    
    def print(self):
        print(self.heapArr)

    def heapEnqueue(self, el):
        self.heapArr.append(el)
        elIndex = len(self.heapArr) - 1
        elParentIndex = int(math.floor((elIndex - 1) / 2)) if elIndex != 0 else 0
        while self.heapArr[0] != el and el > self.heapArr[elParentIndex]:
            # swap el with parent
            tmp = self.heapArr[elParentIndex]
            self.heapArr[elParentIndex] = el
            self.heapArr[elIndex] = tmp
            elIndex = elParentIndex
            elParentIndex = int(math.floor((elIndex - 1) / 2)) if elIndex != 0 else 0
    

    @staticmethod
    def FloydAlgorithm(arr: list) -> list:
        l = math.ceil(len(arr) / 2 - 1)
        for i in reversed(range(l)):
            # restore heap property for the tree whose root is arr[i] with moveDown
            HeapArr.moveDown(arr, i)
        return arr


    def heapDequeue(self):
        # remove element at root and replace with last element
        last = len(self.heapArr) - 1
        self.heapArr[0] = self.heapArr[last]
        del self.heapArr[last]
        # then run top down algorithm to rebalance the tree
        self.moveDown(self.heapArr)
    
    @staticmethod
    def moveDown(arr: list, currIndex: int = 0):
        # first set largest child
        largest = currIndex * 2 + 1
        while largest <= len(arr) - 1:
            if (largest < len(arr) - 1 and arr[largest] < arr[largest + 1]):
                largest += 1
            if (arr[currIndex] < arr[largest]):
                # swap child and parent
                tmp = arr[largest]
                arr[largest] = arr[currIndex]
                arr[currIndex] = tmp
                currIndex = largest
                largest = 2 * currIndex + 1
            else:
                largest = len(arr) + 1 # terminate



# test
h1 = HeapArr(h)
print("Enqueue 15")
h1.print() 
h1.heapEnqueue(15)
h1.print()

h2 = HeapArr(h)
print("Dequeue")
h2.print()
h2.heapDequeue()
h2.print()


print("Starting heap")
h3 = HeapArr(H2)
h3.print()
