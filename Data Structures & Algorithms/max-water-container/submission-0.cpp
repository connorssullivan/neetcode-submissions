class Solution {
private:
    int getMinTower(std::vector<int>& vec, const int num1, const int num2)
    {
        if (num1 >= vec.size() || num2 >= vec.size())
        {
            throw "Invalid Index";
        }
        return std::min(vec[num1],vec[num2]);
    }

public:
    int maxArea(std::vector<int>& heights) {

        int n {static_cast<int>(heights.size())};
        int max_height { 0 };

        for (int i=0; i < n-1; i ++)
        {
            int temp_max_height {0};
            for (int j=i+1; j < n; j++)
            {
                temp_max_height = std::max(temp_max_height, (getMinTower(heights, i, j) * (j - i)));
            }

            max_height = std::max(max_height, temp_max_height);
        }


        return max_height;
        
    }
};