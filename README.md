# C-DSA
Neev Jain
Tanmay More
Harsh Sankhe

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp; // value -> index
        for (int i=0;i<nums.size();i++) {
            int complement=target-nums[i];
            if (mp.count(complement)){ // check if we have seen that needed number
                return {mp[complement], i};
            }
            mp[nums[i]] = i;
        }
        return {}; // not found
    }
};
