#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0)
                res.push_back("FizzBuzz");
            else if (i % 3 == 0) 
                res.push_back("Fizz");
            else if (i % 5 == 0)
                res.push_back("Buzz");
            else
                res.push_back(to_string(i));
        }
        return res;
    }
};

void test(string test_name, int n, vector<string> expected)
{
    vector<string> res = Solution().fizzBuzz(n);
    if (res == expected)
        cout << test_name + " succeed\n";
    else
        cout << test_name + " fail\n";
}

int main()
{
    int n1{3};
    vector<string> expected1{"1","2","Fizz"};
    test("test1", n1, expected1);

    int n2{5};
    vector<string> expected2{"1","2","Fizz","4","Buzz"};
    test("test2", n2, expected2);

    int n3{15};
    vector<string> expected3{"1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"};
    test("test3", n3, expected3);

    return 0;
}
