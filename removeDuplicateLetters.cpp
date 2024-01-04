class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> ansStack;
        unordered_set<char> visited;
        unordered_map<char, int> lo;

        for (int i = 0; i < s.size(); ++i) {
            lo[s[i]] = i;
        }

        for (int i = 0; i < s.size(); ++i) {
            char currentChar = s[i];

            if (visited.count(currentChar)) {
                continue;
            }

            while (!ansStack.empty() && currentChar < ansStack.top() && i < lo[ansStack.top()]) {
                visited.erase(ansStack.top());
                ansStack.pop();
            }

            ansStack.push(currentChar);
            visited.insert(currentChar);
        }

        string ans = "";
        while (!ansStack.empty()) {
            ans = ansStack.top() + ans;
            ansStack.pop();
        }

        return ans;
    }
};
