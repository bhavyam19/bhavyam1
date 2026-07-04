class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int i = 0;
        int steps = 0;
        int capacity1 = capacity;
        while(i<plants.size()){
            if(plants[i]<=capacity1){
                capacity1-=plants[i];
                steps+=1;
                i++;
            }else{
                capacity1 = capacity;
                capacity1-=plants[i];
                steps+=2*(i)+1;
                i++;
            }
        }
        return steps;
    }
};