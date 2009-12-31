#include <cstdio>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

class TimeMap {
    unordered_map<string, map<int, string>> m;
public:
    TimeMap() { }

    void set(string key, string value, int timestamp) {
        m[key].insert({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = m[key].upper_bound(timestamp);
        return it == m[key].begin() ? "" : prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

void test1()
{
    TimeMap *timeMap = new TimeMap();
    timeMap->set("foo", "bar", 1);
    auto res1 = timeMap->get("foo", 1);     // bar
    auto res2 = timeMap->get("foo", 3);     // bar
    timeMap->set("foo", "bar2", 4);
    auto res3 = timeMap->get("foo", 4);     // bar2
    auto res4 = timeMap->get("foo", 5);     // bar2
    if (res1 == "bar" &&
            res2 == "bar" &&
            res3 == "bar2" &&
            res4 == "bar2")
        printf("test1 succeed\n");
    else
        printf("test1 fail\n");
}

int main()
{
    test1();

    return 0;
}

