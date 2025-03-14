class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);
        unordered_map<string, int> emailToAccount; // Maps email to account index
        
        // Initialize disjoint set
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        // Find function with path compression
        auto find = [&](auto self,int x) -> int {
            if (x != parent[x]) {
                parent[x] = self(self,parent[x]);
            }
            return parent[x];
        };
        
        // Union function
        auto unite = [&](int x, int y) -> void {
            parent[find(find,x)] = find(find,y);
        };
        
        // Step 1: Build email to account mapping and merge accounts
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailToAccount.find(email) != emailToAccount.end()) {
                    // If this email already exists, merge the accounts
                    unite(i, emailToAccount[email]);
                } else {
                    // First time seeing this email
                    emailToAccount[email] = i;
                }
            }
        }
        
        // Step 2: Group emails by parent account
        unordered_map<int, set<string>> merged;
        for (int i = 0; i < n; i++) {
            int root = find(find,i);
            for (int j = 1; j < accounts[i].size(); j++) {
                merged[root].insert(accounts[i][j]);
            }
        }
        
        // Step 3: Convert to required output format
        vector<vector<string>> result;
        for (auto& [root, emails] : merged) {
            vector<string> account;
            account.push_back(accounts[root][0]); // Add the name
            account.insert(account.end(), emails.begin(), emails.end());
            result.push_back(account);
        }
        
        return result;
    }
};
