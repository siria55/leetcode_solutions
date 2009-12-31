#include <cstdio>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
    // remove 3 or more consecutive balls
    string updateBoard(string board)
    {
        int start = 0, end = 0;
        int board_len = board.size();
        while (start < board_len) {
            while (end < board_len && board[start] == board[end])
                ++end;  // increse end pointer to one after last position with same color
            if (end - start >= 3) {
                string new_board = board.substr(0, start) + board.substr(end);
                return updateBoard(new_board);
            } else {
                ++start;
            }
        }
        return board;
    }

    int dfs(string board, unordered_map<char, int>& freq, unordered_map<string, int>& cache)
    {
        if (cache.count(board))
            return cache[board];
        int res = INT_MAX;
        int board_len = board.size();
        if (board_len  == 0)
            return 0;
        for (int i = 0; i < board_len; ++i) {
            for (auto& pair : freq) {
                if (pair.second <= 0)
                    continue;
                board.insert(board.begin() + i, pair.first);
                pair.second--;

                string new_board = updateBoard(board);
                int steps = dfs(new_board, freq, cache);
                // steps will be -1, if we cannot remove all balls
                if (steps != -1)
                    res = min(res, steps + 1);

                pair.second++;
                board.erase(board.begin()+i);
            }
        }
        if (res == INT_MAX)
            res = -1;
        cache[board] = res;
        return res;
    }

public:
    int findMinStep(string board, string hand) {
        unordered_map<char, int> freq;
        for (char c : hand)
            ++freq[c];
        unordered_map<string, int> cache;
        return dfs(board, freq, cache);
    }
};

void test(string test_name, string board, string hand, int expected)
{
    int res = Solution().findMinStep(board, hand);
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    string board1 = "WRRBBW";
    string hand1 = "RB";
    int expected1 = -1;
    test("test1", board1, hand1, expected1);

    string board2 = "WWRRBBWW";
    string hand2 = "WRBRW";
    int expected2 = 2;
    test("test2", board2, hand2, expected2);

    string board3 = "G";
    string hand3 = "GGGGG";
    int expected3 = 2;
    test("test3", board3, hand3, expected3);

    string board4 = "RBYYBBRRB";
    string hand4 = "YRBGB";
    int expected4 = 3;
    test("test4", board4, hand4, expected4);

    return 0;
}

