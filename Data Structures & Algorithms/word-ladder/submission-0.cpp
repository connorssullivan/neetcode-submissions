class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::set<string> words(wordList.begin(), wordList.end());

        if (words.find(endWord) == words.end() || beginWord == endWord)
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int res {};

        while (!q.empty())
        {
            res++;
            int len = q.size();
            for (int i {}; i < len; i++)
            {
                string s = q.front(); q.pop();

                if (s == endWord)
                    return res;

                for (int j {}; j < s.length(); j++)
                {
                    char og = s[j];

                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        if (og == c)
                            continue;
                        s[j] = c;
                        if (words.find(s) != words.end())
                        {
                            q.push(s);
                            words.erase(s);
                        }
                    }

                    s[j] = og;
                }
            }
        }

        return 0;
    }
};
