class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // Map holding a map that keeps track of charectors, and a vector of strings that need to get pushed back 
        std::map<std::map<char, int>, std::vector<std::string>> wordCount;

        std::vector<std::vector<std::string>> sol;

        for(int i=0; i < strs.size(); i++){
            
            std::map<char, int> word;

            for(int j=0; j < strs[i].size(); j++){
                word[strs[i][j]]++;
            }

            wordCount[word].push_back(strs[i]);
        }

        int i {};
        for(auto& val : wordCount){
            std::vector<std::string> temp;
            std::cout << ++i << ": ";
            for(auto& str : wordCount[val.first]){
                temp.push_back(str);
            }

            for (int i =0; i<temp.size(); i++)
                std::cout << temp[i] << ", ";
            std::cout << "\n";
            sol.push_back(temp);
        }

        return sol;
    }

};
