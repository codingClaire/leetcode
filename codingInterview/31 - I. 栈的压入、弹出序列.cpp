class Solution
{
public:
    bool validateStackSequences(vector<int> &ins, vector<int> &outs)
    {
        stack<int> st;
        int n = ins.size();
        for (int i = 0, j = 0; i < n; i++)
        {
            st.emplace(ins[i]);
            while (!st.empty() && st.top() == outs[j])
            { // 出栈并且移动j
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};

// 以下是典型错误的解法，因为没有考虑到这种情况
// pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
// 这里应该是true的，但是用下面的解法会显示false，是有问题的
class Solution {
public:
bool check(vector<int> &ins, vector<int> &outs, int left, int right)
{
    if (right > ins.size())
        return true;
    for (int i = 0; i < (right - left + 1) / 2; i++)
    {
        if (ins[left + i] != outs[right - i])
            return false;
    }
    return true;
}

bool validateStackSequences(vector<int> &ins, vector<int> &outs)
{
    int cur_in = 0, cur_out = 0;
    int n = ins.size();
    while (cur_out < n && cur_in < n)
    {
        while (outs[cur_out] != ins[cur_in])
            cur_in++;
        if (check(ins, outs, cur_out, cur_in) == false)
            return false;
        if (cur_in == cur_out)
            cur_in++;
        cur_out = cur_in;
    }
    return true;
}
}
;