#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k) {
  unordered_map<int,int> mp;
  for(int i = 0; i < nums.size(); i++){
    mp[nums[i]]++;
  }
  priority_queue<pair<int,int>> pq;
  for(auto it = mp.begin(); it != mp.end(); it++){
    pq.push({it->second, it->first});
  }
  vector<int> res;
  for(int i = 0; i < k; i++){
    res.push_back(pq.top().second);
    pq.pop();
  }
  return res;
}