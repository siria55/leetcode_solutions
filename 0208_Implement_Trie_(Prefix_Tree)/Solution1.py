class Node:

    def __init__(self):
        self.children = [None] * 26
        self.is_end = False


class Trie:

    def __init__(self):
        self.root = Node()

    def insert(self, word: str) -> None:
        node = self.root
        for ch in word:
            idx = ord(ch) - ord('a')
            if not node.children[idx]:
                node.children[idx] = Node()
            node = node.children[idx]
        node.is_end = True

    def search(self, word: str) -> bool:
        node = self.root
        for ch in word:
            idx = ord(ch) - ord('a')
            if not node.children[idx]:
                return False
            node = node.children[idx]
        return node.is_end

    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for ch in prefix:
            idx = ord(ch) - ord('a')
            if not node.children[idx]:
                return False
            node = node.children[idx]
        return node is not None

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)


def test1():
    obj = Trie()
    obj.insert('apple')
    res1 = obj.search('apple')    # True
    res2 = obj.search('app')      # Flase
    res3 = obj.startsWith('app')  # True
    obj.insert('app')
    res4 = obj.search('app')      # True

    if (res1, res2, res3, res4) == (True, False, True, True):
        print('test1 succeed')
    else:
        print('test1 fail')


if __name__ == '__main__':
    test1()

