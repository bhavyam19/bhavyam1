class Solution {
public:
    long long totalHours(vector<int>& piles, int hourly){
        long long tH = 0;
        for(int i=0;i<piles.size();i++){
            tH += ceil((double)piles[i]/hourly);
        }
        return tH;
    }    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = *max_element(piles.begin(), piles.end());
        int low = 1, high = n;
        while(low<=high){
            int mid = (low+high)/2;
            long long tH = totalHours(piles,mid);
            if(tH<=h){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};