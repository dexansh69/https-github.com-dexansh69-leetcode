class Solution {
public:
    int boutiqueCount(vector<int>& bloomDay, int day, int m, int flowers) {
        int n = bloomDay.size();

        int count = 0;
        int boutiques = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                count++;
            } else {
                boutiques = boutiques + count / flowers;
                count = 0;
            }
        }
            boutiques += count / flowers;
        if (boutiques < m) {
            return -1;
        }
        return boutiques;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int maxDays = *max_element(bloomDay.begin(), bloomDay.end());
        int minDays = *min_element(bloomDay.begin(), bloomDay.end());

        if (n < (long long)m * k) {
            return -1;
        }
        int low = minDays;
        int high = maxDays;
        int ans = -1;
        while (low <= high) {
            int mid = (high + low) / 2;
            int check = boutiqueCount(bloomDay, mid, m, k);
            if (check != -1) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};