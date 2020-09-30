class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            int tar = -nums[i];
            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end) {
                int sum = nums[start] + nums[end];

                if (sum > tar) end--;
                else if (sum < tar) start++;
                else {
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[start]);
                    temp.push_back(nums[end]);
                    res.push_back(temp);

                    while (start < end && nums[start] == temp[1]) start++;
                    while (start < end && nums[end] == temp[2]) end--;
                }
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        return res;
    }
};