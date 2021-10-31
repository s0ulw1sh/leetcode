
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        std::vector<int> out(2);
        int len = nums.size();
      
        for (int i = 0; i < len; ++i) {
            auto f = map.find(target - nums[i]);
            if (f != map.end() && i != f->second) {
                out[0] = i;
                out[1] = f->second;
                break;
            } else {
                map.insert(std::make_pair(nums[i], i));
            }
        }
        
        return out;
    }
};
