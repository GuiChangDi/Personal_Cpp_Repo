#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = sizeof(nums);
        for (int i = 0;i < size -1; i++)
            for(int j = i+1;j < size; j++){
                if (nums[i] + nums[j] == target){
                    return {i,j};
                }
        }
        return {0,0};
    }
};