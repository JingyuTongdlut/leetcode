class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        dfs(s, 0, cur, ans);
        return ans;
    }
private:
    void dfs(string s, int loc, vector<string> &cur, vector<vector<string>> &ans) {
        if(loc == s.size()) {
            ans.push_back(cur);
            return;
        }
        
        for(int i = loc; i < s.size(); ++i) {
            if(!isPalindrome(s, loc, i)) continue;
            cur.push_back(s.substr(loc, i - loc + 1));
            dfs(s, i + 1, cur, ans);
            cur.pop_back();
        }
    }
    
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            ++start; --end;
        }
        return true;
    }
};