#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:

    vector<int> sortArray(vector<int>& nums) {
        insertSort(nums);
        return nums;
    };
    void insertSort(vector<int>& nums){
        int len = nums.size();
        int left,right;
        for (int i = 1; i < len; i++)
        {
            left = 0; right = i-1;
            int value = nums[i];
            while (left<=right)
            {
                int mid = left + (right - left)/2;
                if(nums[mid]<value){
                    left = mid + 1;
                }else
                {
                    right = mid - 1;
                }
            }

            if(left = i){
                continue;
            }
            for (int j = i; j >= left + 1; j--)
            {
                nums[j] = nums[j-1];
            }
            nums[left] = value;
        }
    }
};


int main(){
    Solution s;
    vector<int> test = {5,1,1,2,0,0};
    s.sortArray(test);
    return 0;
}


