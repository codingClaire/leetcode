

/*
5
[".....","..E..",".WO..","....."]
3
[".....","....O","....O","....."]
4
["..E.",".EOW","..W."]
1
[".....","..O..","....."]
41
["E...W..WW",".E...O...","...WO...W","..OWW.O..",".W.WO.W.E","O..O.W...",".OO...W..","..EW.WEE."]
69
["W.W.WE..",".WWWEW..","EWW.WE.E","E.W.E.E.",".OEOO.EO","WE.WOE.W","WW...E..",".WEWO..O","E....E..",".OWE...."]
55
["..E..OEEO.","..O..EEEOE",".EE.WE..OW","..EEWE.W..","...EE.WEE.","W.E...WEE.","WW.WEEE.WW",".WW...WOOO"]
输出：
[]
预期：
[[0,2],[2,2]]
[[0,2],[0,3],[0,5],[0,6],[1,0],[1,8],[3,0],[3,8],[4,0],[6,0],[7,1],[7,4]]
55
[[0,4],[1,0],[3,9],[4,9],[7,5]]
*/

class Solution
{
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // up right down left
    string d[4] = {"up", "right", "down", "left"};

    bool isLegal(int i, int j, vector<string> &plate, int curdir)
    {
        curdir = curdir >= 2 ? curdir - 2 : curdir + 2; // change opposite direction
        if (plate[i][j] != '.')
            return false;
        if (j == 0 && i > 0 && i < plate.size() - 1 && curdir == 1)
            return true;
        if (j == plate[0].size() - 1 && i>0 && i < plate.size() - 1 && curdir == 3)
            return true;
        if (i == 0 && j > 0 && j < plate[0].size() - 1 && curdir == 2)
            return true;
        if (i == plate.size() - 1 && j > 0 && j < plate[0].size() - 1 && curdir == 0)
            return true;
        return false;
    }

    void backtrack(int num, vector<string> &plate, vector<vector<int>> &res, int i, int j, int curdir)
    {
        // cout << "cur num: " << num << " " << i << " " << j << " curdir:" << curdir << " " << d[curdir] << endl;

        if (num < 0 || j < 0 || j > plate[0].size() - 1 || i < 0 || i > plate.size() - 1)
            return;
        if (isLegal(i, j, plate, curdir))
        {
            // cout<<i<<" "<<j<<endl;
            vector<int> tmp = {i, j};
            res.emplace_back(tmp);
        }
        if (plate[i][j] == 'O')
        {
            if (curdir == -1)
            {
                for (int k = 0; k < 4; k++)
                {
                    int new_i = i + dirs[k][0];
                    int new_j = j + dirs[k][1];
                    backtrack(num - 1, plate, res, new_i, new_j, k);
                }
            }
            else
            {
                return;
            }
        }
        else if (plate[i][j] == 'E')
        {
            if (curdir == 0)
                curdir = 4;
            // cout<<i<<" "<<j<<" E  "<<i + dirs[curdir - 1][0]<<" "<< j + dirs[curdir - 1][0]<<endl;
            backtrack(num - 1, plate, res, i + dirs[curdir - 1][0], j + dirs[curdir - 1][1], curdir - 1);
        }
        else if (plate[i][j] == 'W')
        {
            if (curdir == 3)
                curdir = -1;
            backtrack(num - 1, plate, res, i + dirs[curdir + 1][0], j + dirs[curdir + 1][1], curdir + 1);
        }
        else if (plate[i][j] == '.')
        {
            // cout<<i<<" "<<j<<" .  "<<i + dirs[curdir][0]<<" "<< j + dirs[curdir][1]<<endl;
            backtrack(num - 1, plate, res, i + dirs[curdir][0], j + dirs[curdir][1], curdir);
        }
    }

    static bool cmp(vector<int> a, vector<int> b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }

    vector<vector<int>> ballGame(int num, vector<string> &plate)
    {
        vector<vector<int>> res;
        for (int i = 0; i < plate.size(); i++)
        {
            for (int j = 0; j < plate[0].size(); j++)
            {
                if (plate[i][j] == 'O')
                {
                    backtrack(num, plate, res, i, j, -1);
                }
            }
        }
        //cout << res.size() << endl;
        sort(res.begin(), res.end(), cmp);
        auto it = unique(res.begin(), res.end());
        res.erase(it, res.end());
        return res;
    }
};


//// USE SET

class Solution
{
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // up right down left
    set<int> st;
    bool isLegal(int i, int j, vector<string> &plate, int curdir)
    {
        curdir = curdir >= 2 ? curdir - 2 : curdir + 2; // change opposite direction
        if (j == 0 && i > 0 && i < plate.size() - 1 && curdir == 1)
            return true;
        if (j == plate[0].size() - 1 && i>0 &&i < plate.size() - 1 && curdir == 3)
            return true;
        if (i == 0 && j > 0 && j < plate[0].size() - 1 && curdir == 2)
            return true;
        if (i == plate.size() - 1 && j > 0 && j < plate[0].size() - 1 && curdir == 0)
            return true;
        return false;
    }

    void backtrack(int num, vector<string> &plate, vector<vector<int>> &res, int i, int j, int curdir)
    {
        if (num < 0 || j < 0 || j > plate[0].size() - 1 || i < 0 || i > plate.size() - 1)
            return;
        int m = plate[0].size();
        if (plate[i][j]=='.'&&!st.count(i*m + j) && isLegal(i, j, plate, curdir))
        {
            vector<int> tmp = {i, j};
            res.emplace_back(tmp);
            st.insert(i*m + j);
        }
        if (plate[i][j] == 'O')
        {
            if(curdir == -1)
            {
                for (int k = 0; k < 4; k++)
                {
                    int new_i = i + dirs[k][0];
                    int new_j = j + dirs[k][1];
                    backtrack(num - 1, plate, res, new_i, new_j, k);
                }
            }
            else
            {
                return;
            }
        }
        else if (plate[i][j] == 'E')
        {
            if (curdir == 0)
                curdir = 4;
            backtrack(num - 1, plate, res, i + dirs[curdir - 1][0], j + dirs[curdir - 1][1], curdir - 1);
        }
        else if (plate[i][j] == 'W')
        {
            if (curdir == 3)
                curdir = -1;
            backtrack(num - 1, plate, res, i + dirs[curdir + 1][0], j + dirs[curdir + 1][1], curdir + 1);
        }
        else if (plate[i][j] == '.')
        {
            backtrack(num - 1, plate, res, i + dirs[curdir][0], j + dirs[curdir][1], curdir);
        }
    }

    vector<vector<int>> ballGame(int num, vector<string> &plate)
    {
        vector<vector<int>> res;
        for (int i = 0; i < plate.size(); i++)
        {
            for (int j = 0; j < plate[0].size(); j++)
            {
                if (plate[i][j] == 'O')
                {
                    backtrack(num, plate, res, i, j, -1);
                }
            }
        }
        return res;
    }
};