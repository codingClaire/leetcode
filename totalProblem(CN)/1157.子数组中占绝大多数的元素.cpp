/*
 * @lc app=leetcode.cn id=1157 lang=cpp
 *
 * [1157] 子数组中占绝大多数的元素
 */

// @lc code=start
// https://www.youtube.com/watch?v=xghx0yK8ew4

class MajorityChecker
{
    class SegTreeNode
    {
    public:
        SegTreeNode *left;
        SegTreeNode *right;
        int start, end;
        int info, freqDiff; 
        // info：节点对应区间的和
        // freqDiff: 区间里最多的候选元素的频率和其他所有的元素的差 Boyer-Moore投票算法
        SegTreeNode(int a, int b) : start(a), end(b), info(0), freqDiff(0), left(NULL), right(NULL) {}
    };
    void init(SegTreeNode *node, int a, int b) // init for range [a,b]
    {
        if (a == b)
        {
            node->info = arr[a];
            node->freqDiff = 1;
            return;
        }

        int mid = (a + b) / 2;
        if (node->left == NULL)
        {
            node->left = new SegTreeNode(a, mid);
            node->right = new SegTreeNode(mid + 1, b);
        }
        init(node->left, a, mid);
        init(node->right, mid + 1, b);

        if (node->left->info == node->right->info)
        {
            node->info = node->left->info;
            node->freqDiff = node->left->freqDiff + node->right->freqDiff;
        }
        else
        {
            if (node->left->freqDiff >= node->right->freqDiff)
            {
                node->info = node->left->info;
                node->freqDiff = node->left->freqDiff - node->right->freqDiff;
            }
            else
            {
                node->info = node->right->info;
                node->freqDiff = node->right->freqDiff - node->left->freqDiff;
            }
        }
    }

    pair<int, int> queryRange(SegTreeNode *node, int a, int b)
    {
        if (b < node->start || a > node->end)
        {
            return {0, 0};
        }
        if (a <= node->start && b >= node->end)
        {
            return {node->info, node->freqDiff};
        }

        auto L = queryRange(node->left, a, b);
        auto R = queryRange(node->right, a, b);
        if (L.first == R.first)
            return {L.first, L.second + R.second};
        else
        {
            if (L.second >= R.second)
                return {L.first, L.second - R.second};
            else
                return {R.first, R.second - L.second};
        }
    }

    SegTreeNode *root;
    vector<int> arr;
    unordered_map<int, vector<int>> Map;

public:
    MajorityChecker(vector<int> &arr)
    {
        this->arr = arr;
        int n = arr.size();
        root = new SegTreeNode(0, n - 1);
        init(root, 0, n - 1);

        for (int i = 0; i < arr.size(); i++)
            Map[arr[i]].push_back(i);
    }

    int query(int left, int right, int threshold)
    {
        auto [val, freqDiff] = queryRange(root, left, right);

        auto pos1 = lower_bound(Map[val].begin(), Map[val].end(), left);
        auto pos2 = upper_bound(Map[val].begin(), Map[val].end(), right);
        int count = pos2 - pos1;
        if (count >= threshold)
            return val;
        else
            return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
// @lc code=end
// 贪心法 会TLE
class MajorityChecker
{
    unordered_map<int, vector<int>> Map; // val->{pos0,pos1,pos2...}
    vector<pair<int, int>> q;            // {freq, val}

public:
    MajorityChecker(vector<int> &arr)
    {
        // Map存储位置信息
        for (int i = 0; i < arr.size(); i++)
            Map[arr[i]].push_back(i);
        for (auto x : Map)
            q.push_back({x.second.size(), x.first});
        // 获得从大到大排序的{频次，对应元素}
        sort(q.begin(), q.end());
        reverse(q.begin(), q.end());
    }

    int query(int left, int right, int threshold)
    {
        int total = right - left + 1;
        for (int i = 0; i < q.size(); i++)
        {
            // 遍历到当前元素
            int num = q[i].second;
            // 二分查找
            // num: {pos0, l, pos1, pos2,r, pos3...}
            // 最大的小于等于l的位置
            int pos1 = lower_bound(Map[num].begin(), Map[num].end(), left) - Map[num].begin();
            // 最小的大于r的位置
            int pos2 = upper_bound(Map[num].begin(), Map[num].end(), right) - Map[num].begin();
            // 直接返回，满足条件的肯定是频率最大的
            if (pos2 - pos1 >= threshold)
                return num;
            else
                total -= pos2 - pos1; // 更新total，配合下面的剪枝
            // 剪枝：区间长度已经小于threshold了，肯定找不到
            if (total < threshold)
                return -1;
            // 剪枝：当前元素的总的频次少于threshold，肯定找不到
            if (Map[num].size() < threshold)
                return -1;
        }
        return -1;
    }
};