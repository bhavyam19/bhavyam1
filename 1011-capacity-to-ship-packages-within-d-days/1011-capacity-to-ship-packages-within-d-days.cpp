class Solution {
public:
    int findDays(vector<int>& weights, int capacity){
        int load = 0, day = 1;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>capacity){
                day+=1;
                load = weights[i];
            }else{
                load+=weights[i];
            }
        }
        return day;
    }
    int sumOfLoads(vector<int>& weights){
        int sum = 0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        return sum;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = sumOfLoads(weights);
        while(low<=high){
            int mid = (low+high)/2;
            int day = findDays(weights,mid);
            if(day<=days){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};