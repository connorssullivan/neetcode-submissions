#include <vector>



class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int i {0};

        for (; i < matrix.size(); i++)
        {
            if (target > matrix[i][static_cast<int>(matrix[i].size()-1)])
            {
                continue;
            }
            else break;
            
        }

        int left {0};
        int right {static_cast<int>(matrix[i].size()-1)};

        if (i == matrix.size())
            return false;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            
            if (matrix[i][mid] > target)
                right = mid -1;
            else if (matrix[i][mid] < target)
                left = mid +1;
            else 
                return true;
                
        }

        return false;
    }
};