#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        string word, wordSort;
        for(int i = 0; i < strs.size(); i++){
            word = strs[i];
            wordSort = strs[i];
            sort(wordSort.begin(), wordSort.end());
            mp[wordSort].push_back(word);
        }
        vector<vector<string>> res;
        for(auto it = mp.begin(); it != mp.end(); it++){
            res.push_back(it->second);
        }
        return res;
}