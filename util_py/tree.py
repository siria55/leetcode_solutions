class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def in_order(node, in_list):
    if not node:
        return
    in_order(node.left, in_list)
    in_list.append(node.val)
    in_order(node.right, in_list)


def get_inorder_list(tree):
    in_list = []
    in_order(tree, in_list)
    return in_list


def is_equal_tree(t1, t2):
    if not t1 and not t2:
        return True
    if not t1 or not t2:
        return False
    if t1.val != t2.val:
        return False
    return is_equal_tree(t1.left, t2.left) and is_equal_tree(t1.right, t2.right)


def is_balanced_dfs(node):
    if not node:
        return 0
    l = is_balanced_dfs(node.left)
    r = is_balanced_dfs(node.right)
    if l == -1 or r == -1:
        return -1
    if abs(l-r) > 1:
        return -1
    return max(l, r) + 1


def is_balanced_tree(tree):
    if not tree:
        return True
    return is_balanced_dfs(tree) != -1

