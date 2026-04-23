class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> sol;
        auto order = [] (vector<int>& p1, vector<int>& p2) {
            int d1 = p1[0]*p1[0] + p1[1]*p1[1];
            int d2 = p2[0]*p2[0] + p2[1]*p2[1];
            return d1 > d2; // max heap
        };
        
        priority_queue<vector<int>, vector<vector<int>>,decltype(order)> pq (order);  

        for (auto& p : points)
        {
            pq.push(p);
        } 

        while (!pq.empty() && k > 0)
        {
            sol.push_back(pq.top());
            pq.pop();
            k--;
        }

        
            return sol;
        


    }
};
