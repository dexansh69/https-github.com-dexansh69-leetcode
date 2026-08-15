class Solution {
public:
// function to check number of total hours of bananas
long long speedCheck(vector<int>& piles,int speed){
    int n= piles.size();
    long long hours=0;
for(int i=0;i<n;i++){
 hours = hours+ (long long)ceil((double)piles[i]/speed);
}
return hours;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        // finding the highest hours
        int n= piles.size();
        int maxi=0;
        int low=1;
        
        for(int i=0;i<n;i++){
            if( piles[i]>=maxi){
                maxi=piles[i];
            }
        }

        int ans=0;
        int high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            long long hours = speedCheck(piles,mid);
            if(hours<=h){
                ans=mid;
                high=mid-1;
            }
            else if(hours>h){
                    low = mid+1;
            }
            
        }
        return ans;

    }
};