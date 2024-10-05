#include <iostream>
#include <vector>
using namespace std;

// MergeSort da finire
class Solution
{
public:
  vector<int> sortArray(vector<int> &nums)
  {
    if (nums.size() >= 2)
    {
      int q = nums.size() / 2;
      return divideArray(nums, 0, nums.size() - 1);
    }
    else
    {
      return nums;
    }
  }

  vector<int> divideArray(vector<int> &nums, int init, int end)
  {
    int q = nums.size() / 2;
    // vector<int> firstArr = vector<int>(nums.begin(), nums.begin() + q);
    // vector<int> secondArr = vector<int>(nums.begin() + q, nums.end());
    if (q > 0)
    {
      divideArray(nums, init, q);
      divideArray(nums, q + 1, end);
      return mergeSort(nums, init, q, end);
    }
    else
    {

      return nums;
    }
  }

  vector<int> mergeSort(vector<int> &nums, int init, int q, int end)
  {
    vector<int> merge = vector<int>();
    int x, y = 0;
    for (int i = init; i < end; i++)
    {
      if (y + q >= end)
      {
        merge.push_back(nums[x]);
        x++;
      }
      else if (x >= q)
      {
        merge.push_back(nums[y + q]);
        y++;
      }
      else if (nums[x] <= nums[y])
      {
        merge.push_back(nums[x]);
        x++;
      }
      else
      {
        merge.push_back(nums[y + q]);
        y++;
      }
    }
    return merge;
  }
};