//
// Created by 鲁红呈 on 2023/11/14.
//
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>> q;
        for(int i=0;i<k;i++){
            q.emplace(nums[i],i);
        }
        vector<int> ans = {q.top().first};
        for(int i=k;i<n;i++){
            q.emplace(nums[i],i);
            while(q.top().second<=i-k){
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};