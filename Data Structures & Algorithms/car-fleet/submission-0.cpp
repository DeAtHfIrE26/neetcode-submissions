class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars(n);
        
        for (int i = 0; i < n; i++){
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.rbegin(), cars.rend());

        int fleet = 0;
        double cur = 0;

        for(auto& [p,s] : cars){
            double t  = (double)(target - p ) / (s);
            if ( t > cur){
                fleet++;
                cur = t;
            }
        }
        return fleet;
    }
};