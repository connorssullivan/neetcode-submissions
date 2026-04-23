#include <vector>

class MedianFinder {
private:
    std::vector<int> m_nums;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        m_nums.push_back(num);
    }
    
    double findMedian() {
        if (m_nums.size() == 1)
            return m_nums[0];
        std::sort(m_nums.begin(), m_nums.end());

        int mid = (m_nums.size()-1) / 2;
        double med = m_nums[mid];

        if (m_nums.size() % 2 == 0) // 0 1 2 3
            med = (med + m_nums[mid+1]) / 2.0;

        return med;
    }
};
