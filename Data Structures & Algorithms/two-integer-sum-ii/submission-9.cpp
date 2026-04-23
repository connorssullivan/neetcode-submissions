class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int right = numbers.size() - 1;
        int left {};

        std::vector<int> solution;

        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
            {
                cout << "Left: " << numbers[left] << "\n";
                cout << "Right: " << numbers[right] << "\n";
                solution.push_back(left+1);
                solution.push_back(right+1);
                break;
            }

            if (sum < target)
                left++;
            if (sum > target)
                right--;
        }

        return solution;
    }
};
