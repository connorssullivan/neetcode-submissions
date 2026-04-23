class Solution {
public:

    std::string encode(std::vector<std::string>& strs) {

        std::string encoded;

        for (auto& s : strs)
        {
            encoded += std::to_string(s.size());
            encoded += "...";
            encoded += s;
        }

        return encoded;
    }

    std::vector<std::string> decode(std::string s) {
        std::string del = "...";

        std::vector<std::string> sol;

        int last_end_of_string {};

        for (int i {}; i < s.size(); i++)
        {
            if (s[i] == '.' && s[i+1] == '.' && s[i+2] == '.')
            {
                size_t start = last_end_of_string;
                size_t end   = i; // end position (like delimiter index)
                int len = std::stoi(s.substr(start, end - start));
                i += 3;

                sol.emplace_back(s.substr(i, len));
                last_end_of_string = i + len;
                i += len;
            }
        }

        return sol;
    }
};
