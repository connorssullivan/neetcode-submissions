class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> m_pq;
    int m_k;
public:
    KthLargest(int k, vector<int>& nums) {
        for (const auto n : nums)
        {
            m_pq.push(n);
        }
        m_k = k;

        while (m_pq.size() > m_k)
        {
            m_pq.pop();
        }
    }
    
    int add(int val) {
        m_pq.push(val);

        while (m_pq.size() > m_k)
            m_pq.pop();

        return m_pq.top();
    }
};
