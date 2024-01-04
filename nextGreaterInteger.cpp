class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> myMap;
        stack<int> stk;
        for (int i : nums2) {
            while (!stk.empty() && stk.top() < i) {
                myMap[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            myMap[stk.top()] = -1;
            stk.pop();
        }
        for (int i : nums1) {
            ans.push_back(myMap[i]);
        }

        return ans;
    }
};