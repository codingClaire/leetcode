class Solution
{
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
    {
        int ener_train = 0, exp_train = 0;
        // energy
        int ener_sum = 0;
        for (auto &e : energy)
            ener_sum += e;
        ener_train = ener_sum + 1 - initialEnergy;
        // experience
        int cur_exp = initialExperience;
        for (auto &e : experience)
        {
            if (cur_exp <= e)
            {
                exp_train += e - cur_exp + 1;
                cur_exp += exp_train;
            }
            cur_exp += e;
        }
        // 周赛最后一个测例没过
        //是因为按照前面的算法如果初始的energy远远超过的情况下，ener_train会算成负数
        //所以最后要判断一下...
        return ener_train < 0 ? 0 : ener_train + exp_train;
    }
};