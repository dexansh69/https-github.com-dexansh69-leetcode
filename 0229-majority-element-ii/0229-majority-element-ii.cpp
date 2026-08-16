class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
       

        if (nums.size() == 1) {
            return nums;
        }
        int n = nums.size();
        int majority = n / 3;
        int cnt1 = 0;
        int cnt2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0&& nums[i]!=el2) {
                cnt1 = 1;
                el1 = nums[i];
            } else if (cnt2 == 0 && nums[i]!=el1) {
                cnt2 = 1;
                el2 = nums[i];
            } else if (el1 == nums[i])
                cnt1++;
            else if (el2 == nums[i])
                cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        // to check if they are majority or not;
        int check = 0;
        for (int i = 0; i < n; i++) {
            if (el1 == nums[i]) {
                check++;
            }
        }
        if (check > majority) {
            ans.push_back(el1);
        }
        check = 0;
        for (int i = 0; i < n; i++) {
            if (el2 == nums[i]) {
                check++;
            }
        }
        if (check > majority) {
            ans.push_back(el2);
        }
        return ans;
      
    }
};