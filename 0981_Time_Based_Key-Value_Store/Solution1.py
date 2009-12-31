from collections import defaultdict

class TimeMap:

    def __init__(self):
        self.map = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.map[key].append((timestamp, value))


    def get(self, key: str, timestamp: int) -> str:
        values = self.map[key]
        if not values:
            return ''
        l, r = 0, len(values) - 1
        while l < r:
            m = l + (r - l) // 2 + 1     # biased to right
            pre_time, v = values[m]
            if pre_time > timestamp:
                r = m - 1
            else:
                l = m
        return values[l][1] if values[l][0] <= timestamp else ''


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)

def test1():
    obj = TimeMap()
    obj.set('foo', 'bar', 1)
    res1 = obj.get('foo', 1)    # bar
    res2 = obj.get('foo', 3)    # bar
    obj.set('foo', 'bar2', 4)
    res3 = obj.get('foo', 4)    # bar2
    res4 = obj.get('foo', 5)    # bar2
    if (res1, res2, res3, res4) == ('bar', 'bar', 'bar2', 'bar2'):
        print('test1 succeed')
    else:
        print('test1 succeed')

if __name__ == '__main__':
    test1()

