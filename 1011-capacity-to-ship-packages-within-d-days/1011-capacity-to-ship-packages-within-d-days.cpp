class Solution {
public:
// checking the number of days
int shipDay(vector<int>& weights,int weightCap){
    int days=1;
    int weight=0;
    for(int x:weights){
        weight +=x;
        if(weight>weightCap){
            weight=x;
            days++;
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        long long max=0;
        // finding the max weight cap of the ship
        for(int i=0;i<n;i++){
            max +=weights[i];
        }
        int low = *max_element(weights.begin(), weights.end());
        int high=max;
        int ans=0;
        // Binary search
        while(low<=high){
            long long mid=(high+low)/2;
            int check=shipDay(weights,mid);

            if(check<=days){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};