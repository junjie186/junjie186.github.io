#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target, int low, int high)
{
    if (low < 0 || high >= nums.size())
    {
        return -1;
    }
    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    int mid = search(nums, target, low, high);
    if (mid == -1)
    {
        return {-1, -1};
    }
    int right = mid;
    int left = mid;
    
    for (int res = mid; res != -1; res = search(nums, target, low, left - 1))
    {
        left = res;
    }
    for (int res = mid; res != -1; res = search(nums, target, right + 1, high))
    {
        right = res;
    }
    return {left, right};
}



int main(){
    vector<int> a={5,7,7,8,8,10};
    searchRange(a,8);
}