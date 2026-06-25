class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        

        while (!q.empty()) {
            int n = q.size();
            bool fx = false, fy = false;

            while (n--) {
                TreeNode* cur = q.front();
                q.pop();

                
                if (cur->left && cur->right) {
                    int l = cur->left->val, r = cur->right->val;
                    if ((l == x && r == y) || (l == y && r == x))
                        return false;
                }

                if (cur->val == x) fx = true;
                if (cur->val == y) fy = true;

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }

            if (fx && fy) return true;   // same level
            if (fx || fy) return false;  // only one found at this level
        }

        return false;
    }
};