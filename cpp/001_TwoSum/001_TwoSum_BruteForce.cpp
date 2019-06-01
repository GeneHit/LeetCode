// Source : https://leetcode.com/problems/two-sum/submissions/
// Author : Yongqiang Yu
// Date   : 2019-06-01

/********************************************************************************** 
* 
* Design LeetCode class and implement a twoSum function.
* 
**********************************************************************************/
class LeetCode {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unsigned int length=nums.size();
        vector<int> indices;
        for(unsigned int i=0;i<length;i++) {
            for(unsigned int j=i+1;j<length;j++) {
                if(target == (nums[i]+nums[j])) {
                    indices.push_back(i);
                    indices.push_back(j);
                    return indices;
                }
            }
        }
        return indices;
    }
};
