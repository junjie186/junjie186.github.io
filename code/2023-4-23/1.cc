#include <iostream>
#include <vector>
using namespace std;

int monotoneIncreasingDigits(int n)
{
    vector<int> nums;
    while (n != 0)
    {
        nums.push_back(n % 10);
        n /= 10;
    }
    for (int k = 0; k < nums.size(); k++)
    {
        cout << nums[k];
    }
    vector<int> result;
    result.push_back(nums.back());
    int pre = 0;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] > result.back())
        {
            result.push_back(nums[i]);
            pre = result.size()-1;
        }
        else if (nums[i] == result.back())
        {
            result.push_back(nums[i]);
        }
        else
        {
            result[pre] -= 1;
            for (int k = 0; k < result.size(); k++)
            {
                cout << result[k];
            }
            for (int j = pre + 1; j < result.size(); j++)
            {
                result[j] = 9;
            }
            int tmp = nums.size() - result.size();
            while (tmp--)
            {
                result.push_back(9);
            }
            break;
        }
    }
    int res = 0;
    for (int i = 0; i < result.size(); i++)
    {
        res = 10 * res + result[i];
    }
    return res;
}

int main()
{
    monotoneIncreasingDigits(399443);
}