class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def maxPathSum(root):
    max_sum = float('-inf')

    def dfs(node):
        nonlocal max_sum
        if not node:
            return 0

        left = max(dfs(node.left), 0)
        right = max(dfs(node.right), 0)

        current = node.val + left + right
        max_sum = max(max_sum, current)

        return node.val + max(left, right)

    dfs(root)
    return max_sum

# создаём дерево
root = TreeNode(5)
root.left = TreeNode(2)
root.right = TreeNode(-3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(1)
root.right.right = TreeNode(6)

# вычисляем
print("Максимальный путь:", maxPathSum(root))