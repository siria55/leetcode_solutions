#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        int s_count[10] = {0}, g_count[10] = {0};
        int len = secret.size();
        for (int i = 0; i < len; ++i) {
            if (secret[i] == guess[i])
                ++bulls;
            else {
                ++s_count[secret[i]-'0'];
                ++g_count[guess[i]-'0'];
            }
        }
        for (int i = 0; i < 10; ++i) {
            cows += min(s_count[i], g_count[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

void test(string test_name, string secret, string guess, string expected)
{
    string res = Solution().getHint(secret, guess);
    // printf("res = %s\n", res.c_str());
    if (res == expected)
        printf("%s succeed\n", test_name.c_str());
    else
        printf("%s fail\n", test_name.c_str());
}

int main()
{
    string secret1 = "1807";
    string guess1 = "7810";
    string expected1 = "1A3B";
    test("test1", secret1, guess1, expected1);

    string secret2 = "1123";
    string guess2 = "0111";
    string expected2 = "1A1B";
    test("test2", secret2, guess2, expected2);

    string secret3 = "1";
    string guess3 = "0";
    string expected3 = "0A0B";
    test("test3", secret3, guess3, expected3);

    string secret4 = "1";
    string guess4 = "1";
    string expected4 = "1A0B";
    test("test4", secret4, guess4, expected4);

    return 0;
}
