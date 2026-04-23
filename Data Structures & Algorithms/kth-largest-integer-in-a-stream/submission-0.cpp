#include <vector>
#include <queue>

class KthLargest {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> m_minHeap;
    int m_k;
public:
    KthLargest(int k, std::vector<int>& nums) {
        m_k = k;

        for (int num : nums)
        {
            m_minHeap.push(num);

            if (m_minHeap.size() > m_k)
                m_minHeap.pop();
        }
    }
    
    int add(int val) {
        m_minHeap.push(val);

        if (m_minHeap.size() > m_k)
            m_minHeap.pop();
        
        return m_minHeap.top();
    }
};
