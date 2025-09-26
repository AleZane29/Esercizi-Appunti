class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size(), 1);
    int prefix = 1;
    int postfix = 1;
    for (int i = 0; i < nums.size(); i++) {
      res[i] *= prefix;
      res[nums.size() - 1 - i] *= postfix;
      prefix *= nums[i];
      postfix *= nums[nums.size() - 1 - i];
    }
    return res;
  }
};