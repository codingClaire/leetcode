class Solution
{
public:
    int wateringPlants(vector<int> &plants, int capacity)
    {
        int step = 0;
        int curc = capacity, curp = 0; //current capacity and position
        for (int i = 0; i < plants.size(); i++)
        {
            if (curc >= plants[i])
            {
                curc -= plants[i];
                curp = i;
                step++;
            }
            else
            {
                step = step + (curp + 1) * 2;
                curc = capacity;
                i = curp;
            }
        }
        return step;
    }
};