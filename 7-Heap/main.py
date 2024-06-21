import MaxHeap as max
import MinHeap as min
   
lst=[2,17,22,10,8,37,14,19,7,6,5,12,25,30]  
heap = min.MinHeap(lst)

# while not heap.empty():
#   print(heap.pop(),end=",")

res=heap.find_smaller_value(10)

print(res)   
                