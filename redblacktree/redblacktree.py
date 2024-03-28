class RedBlackNode:
    def __init__(self, key, color):
        self.key = key
        self.left = None
        self.right = None
        self.color = color  # 0 for black, 1 for red

class RedBlackTree:
    def __init__(self):
        self.root = None

    def rotate_left(self, node):
        temp = node.right
        node.right = temp.left
        temp.left = node
        return temp

    def rotate_right(self, node):
        temp = node.left
        node.left = temp.right
        temp.right = node
        return temp

    def is_red(self, node):
        if node is None:
            return False
        return node.color == 1

    def flip_colors(self, node):
        node.color = 1
        node.left.color = 0
        node.right.color = 0

    def insert(self, node, key):
        if node is None:
            return RedBlackNode(key, 1)  # New node is always red

        if key < node.key:
            node.left = self.insert(node.left, key)
        elif key > node.key:
            node.right = self.insert(node.right, key)

        if self.is_red(node.right) and not self.is_red(node.left):
            node = self.rotate_left(node)
        if self.is_red(node.left) and self.is_red(node.left.left):
            node = self.rotate_right(node)
        if self.is_red(node.left) and self.is_red(node.right):
            self.flip_colors(node)

        return node

    def insert_key(self, key):
        self.root = self.insert(self.root, key)
        self.root.color = 0  # Root is always black

    def inorder(self, node):
        if node is not None:
            self.inorder(node.left)
            print(node.key, end=" ")
            self.inorder(node.right)

# Example Usage:
rb_tree = RedBlackTree()
keys = [10, 20, 30, 40, 50, 25]
for key in keys:
    rb_tree.insert_key(key)

rb_tree.inorder(rb_tree.root)
