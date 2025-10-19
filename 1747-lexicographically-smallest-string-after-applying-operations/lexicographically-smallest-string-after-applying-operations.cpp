class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> visited;
        string ans = s;
        int n = s.size();

        auto add_op = [&](const string &t) -> string {
            string res = t;
            for (int i = 1; i < n; i += 2) {
                int new_digit = ((t[i] - '0') + a) % 10;
                res[i] = char('0' + new_digit);
            }
            return res;
        };

        auto rotate_op = [&](const string &t) -> string {
            return t.substr(n - b) + t.substr(0, n - b);
        };

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            if (cur < ans) ans = cur;
            string added = add_op(cur);
            if (!visited.count(added)) {
                visited.insert(added);
                q.push(added);
            }
            string rotated = rotate_op(cur);
            if (!visited.count(rotated)) {
                visited.insert(rotated);
                q.push(rotated);
            }
        }

        return ans;
    }
};
 