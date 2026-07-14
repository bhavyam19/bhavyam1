class Solution {
public:
    int findStudents(vector<int> &nums, int pages){
        int cntStudents = 1;
        long long pagesStudent = 0;
        for(int i=0;i<nums.size();i++){
            if(pagesStudent+nums[i]<=pages){
                pagesStudent+=nums[i];
            }else{
                pagesStudent=nums[i];
                cntStudents+=1;
            }
        }
        return cntStudents;
    }   
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            int students = findStudents(nums,mid);
            if(students>k){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};