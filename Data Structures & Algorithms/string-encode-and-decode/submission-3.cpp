class Solution {
public:
    std::string encode(std::vector<std::string>& strs) {
        std::string sol;
        for (const auto& str : strs) {
            sol += std::to_string(str.size()) + "#" + str;
        }
        return sol;
    }

    std::vector<std::string> decode(const std::string& s) {
        std::vector<std::string> words;
        size_t i = 0;

        while (i < s.size()) {
            // Find length prefix
            size_t j = i;
            while (s[j] != '#') j++;

            int len = std::stoi(s.substr(i, j - i));
            j++; // skip '#'

            // Extract the word
            words.push_back(s.substr(j, len));

            // Move to next encoded string
            i = j + len;
        }

        return words;
    }
};
