#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    vector<string> num2str_small =  {
        "Zero",
        "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
    };
    vector<string> num2str_medium = {
        "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety",
    };
    vector<string> num2str_large = {
        "Billion", "Million", "Thousand", "",
    };

    string num2str(int x)
    {
        string res = "";
        if (x >= 100) {
            res += num2str_small[x / 100] + " Hundred ";
            x %= 100;
        }
        if (x >= 20) {
            res += num2str_medium[x / 10] + " ";
            x %= 10;
        }
        if (x != 0)
            res += num2str_small[x] + " ";
        return res;
    }
        
public:
    string numberToWords(int num) {
        if (num <= 19) return num2str_small[num];
        string res = "";
        for (int i = (int)1e9, j = 0; i >= 1; i /= 1000, j++) {
            if (num < i) continue;
            res += num2str(num / i) + num2str_large[j] + " ";
            num %= i;
        }
        while (res.back() == ' ')
            res.pop_back();
        return res;
    }
};

void test(string test_name, int num, string expected)
{
    string res = Solution().numberToWords(num);
    if (res == expected)
        cout << test_name + " succeed\n";
    else
        cout << test_name + " fail\n";
}

int main()
{
    int num1 = 123;
    string expected1 = "One Hundred Twenty Three";
    test("test1", num1, expected1);

    int num2 = 12345;
    string expected2 = "Twelve Thousand Three Hundred Forty Five";
    test("test2", num2, expected2);

    int num3 = 1234567;
    string expected3 = "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven";
    test("test3", num3, expected3);

    int num4 = 1234567891;
    string expected4 = "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One";
    test("test4", num4, expected4);
}

