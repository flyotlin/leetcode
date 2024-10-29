#include <iostream>
#include <vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];
            if (map.find(t) == map.end()) {
                // cout << "Not found" << endl;
                continue;
            }
            if (map[t] == i) {
                continue;
            }
            // cout << i << " " << map[t] << endl;
            // cout << nums[i] << " " << nums[map[t]] << endl;
            res.push_back(i);
            res.push_back(map[t]);
            return res;
        }
        return nums;
    }
};