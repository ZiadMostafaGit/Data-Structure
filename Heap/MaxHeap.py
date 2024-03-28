
import MinHeap as min



class MaxHeep:
    def __init__(self,lst) -> None:
        neglst=[-x for x in lst]
        self.Max=min.MinHeap(neglst)
             
    
    def top(self):
        return self.Max.top()
    def empty(self):
        return self.Max.empty()
    def push(self,node):
        self.Max.push(-node)

    def pop(self):
        return -self.Max.pop()
        


































    
    








'''
   def __init__(self) -> None:
        self.array = []
        self.size = 0

    def _left(self, node):
        p = 2 * node + 1
        if p >= self.size:
            return -1
        return int(p)

    def _right(self, node):
        p = 2 * node + 2
        if p >= self.size:
            return -1
        return int(p)

    def _parent(self, node):
        return -1 if node == 0 else (node - 1) // 2

    def top(self):
        assert not self.empty()
        return self.array[0]

    def empty(self):
        return self.size == 0

    def push(self, node):
        if self.size + 1 > len(self.array):
            self.array.append(None)
        self.array[self.size] = node
        self.size += 1
        self.heapify_up(self.size - 1)

    def heapify_up(self, child):
        parent = self._parent(child)
        if parent == -1 or self.array[parent] > self.array[child]:
            return
        self.array[child], self.array[parent] = self.array[parent], self.array[child]
        self.heapify_up(parent)

    def pop(self):
        assert not self.empty()
        self.size -= 1
        result = self.array[0]
        self.array[0] = self.array[self.size]
        self.heapify_down(0)
        return result

    def heapify_down(self, parent):
        left_child = self._left(parent)
        right_child = self._right(parent)
        if left_child == -1:
            return
        if right_child != -1 and self.array[right_child] > self.array[left_child]:
            left_child = right_child

        if self.array[parent] < self.array[left_child]:
            self.array[parent], self.array[left_child] = self.array[left_child], self.array[parent]
            self.heapify_down(left_child)

   
   
   
   
   
   
   ''' 