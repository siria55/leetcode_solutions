#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class SummaryRanges {
public:
    vector<vector<int>> vv;
    unordered_set<int> s;
    
    int b_search(int target, int pos)
    {
        int l = 0, r = vv.size() - 1, res;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (vv[m][pos] == target) return m;
            else if (vv[m][pos] < target) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }

    SummaryRanges() {
    }
    
    void addNum(int val) {
        if (s.count(val)) return;
        s.insert(val);
        
        if (s.count(val-1) && s.count(val+1)) {
            // merge [x, val-1] and [val+1, x]
            int l = b_search(val-1, 1);
            int r = b_search(val+1, 0);
            vv[l][1] = vv[r][1];
            vv.erase(vv.begin()+r);
        } else if (s.count(val-1)) {
            // change [x, val-1] to [x, val]
            int pos = b_search(val-1, 1);
            vv[pos][1] = val;
        } else if (s.count(val+1)) {
            int pos = b_search(val+1, 0);
            vv[pos][0] = val;
        } else {
            vv.push_back(vector<int>{val, val});
        }
        sort(vv.begin(), vv.end());
    }
    
    vector<vector<int>> getIntervals() {
        return vv;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
using vv = vector<vector<int>>;

void test1()
{
    SummaryRanges summaryRanges = SummaryRanges();
    summaryRanges.addNum(1);                        // arr = [1]
    auto res1 = summaryRanges.getIntervals();       // return [[1,1]]
    summaryRanges.addNum(3);                        // arr = [1,3]
    auto res2 = summaryRanges.getIntervals();       // return [[1,1],[3,3]]
    summaryRanges.addNum(7);                        // arr = [1,3,7]
    auto res3 = summaryRanges.getIntervals();       // return [[1,1],[3,3],[7,7]]
    summaryRanges.addNum(2);                        // arr = [1,2,3,7]
    auto res4 = summaryRanges.getIntervals();       // return [[1,3], [7,7]]
    summaryRanges.addNum(6);                        // arr = [1,2,3,6,7]
    auto res5 = summaryRanges.getIntervals();       // return [[1,3],[6,7]]
    if (res1 == vv{{1,1}} &&
            res2 == vv{{1,1},{3,3}} &&
            res3 == vv{{1,1}, {3,3}, {7,7}} &&
            res4 == vv{{1,3}, {7,7}} &&
            res5 == vv{{1,3}, {6,7}})
        cout << "test1 succeed.\n ";
    else
        cout << "test1 fail.\n";
}

int main()
{
    test1();

    return 0;
}
