class Solution {
public:
        int sumResult(vector<int> & nums, int divisor) {
            int n = nums.size();
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum = sum+ceil((double)nums[i] / divisor);
            }
            return sum;
        }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int highest = *max_element(nums.begin(), nums.end());
        int low = 1;
        int high = highest;
        int result = 0;
        int sum=0;

        while (low <= high) {
            long long mid = (low + high) / 2;
            // now check the sum of divisors
            sum=sumResult(nums,mid);
            if (sum <= threshold) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};