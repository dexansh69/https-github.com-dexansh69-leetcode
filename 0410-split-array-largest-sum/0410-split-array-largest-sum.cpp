class Solution {
public:
int checkValid(vector<int>& nums,int lock){
    int sum=0;
    int count=1;
    for(int x : nums){
        
        if(sum + x <= lock){
                sum+=x;
        }else{
            sum=x;
            count++;
        }
    }
   return count;
}
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int high=0;
        for(int i=0;i<n;i++){
             high+=nums[i];
        }
        int ans=0;
        while(low<=high){
            int mid=(high+low)/2;
            int count = checkValid(nums,mid);
            if(count<=k){
                
                high=mid-1;

                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};