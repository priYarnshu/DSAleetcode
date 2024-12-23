class Solution {
public:
    int solve(vector<int>& vec) {
        int swaps = 0;
        vector<int> v1 = vec;  
        sort(v1.begin(), v1.end());  
        unordered_map<int, int> mp;

      
        for (int i = 0; i < vec.size(); i++) {
            mp[vec[i]] = i;
        }

       
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == v1[i]) continue;  

            int currIdx = mp[v1[i]];  
            mp[vec[i]] = currIdx;    
            swap(vec[i], vec[currIdx]);
            swaps++;
        }
        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int result = 0;

        while (!que.empty()) {
            int n = que.size();
            vector<int> vec;

           
            while (n--) {
                TreeNode* temp = que.front();
                que.pop();
                vec.push_back(temp->val);

                if (temp->left) que.push(temp->left);
                if (temp->right) que.push(temp->right);
            }

            result += solve(vec);  
        }
        return result;
    }
};
