class FoodRatings
{
private:
    unordered_map<string, vector<string>> c2f;
    unordered_map<string, string> f2c;
    unordered_map<string, int> f2r;
    unordered_map<string, unordered_map<int, vector<string>>> mp;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        for (int i = 0; i < foods.size(); i++)
        {
            f2r[foods[i]] = ratings[i];
            f2c[foods[i]] = cuisines[i];
            mp[cuisines[i]][ratings[i]].emplace_back(foods[i]);
        }
    }

    void changeRating(string food, int newRating)
    {
        string cuisine = f2c[food];
        int rating = f2r[food];
        for (auto iter = mp[cuisine][rating].begin(); iter != mp[cuisine][rating].end(); iter++)
        {
            if (*iter == food)
            {
                mp[cuisine][rating].erase(iter);
                break;
            }
        }
        mp[cuisine][newRating].emplace_back(food);
    }

    string highestRated(string cuisine)
    {
        vector<int> tmp;
        for (auto iter : mp[cuisine])
        {
            if (iter.second.size() != 0)
                tmp.emplace_back(iter.first);
        }
        int maxrating = *max_element(tmp.begin(), tmp.end());
        sort(mp[cuisine][maxrating].begin(), mp[cuisine][maxrating].end());
        return mp[cuisine][maxrating][0];
    }
};





// TLE
class FoodRatings
{
private:
    unordered_map<string, vector<string>> c2f;
    unordered_map<string, int> f2r;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        for (int i = 0; i < foods.size(); i++)
        {
            if (!c2f.count(cuisines[i]))
            {
                c2f[cuisines[i]] = {};
            }
            c2f[cuisines[i]].emplace_back(foods[i]);
            f2r[foods[i]] = ratings[i];
        }
    }

    void changeRating(string food, int newRating)
    {
        f2r[food] = newRating;
    }

    string highestRated(string cuisine)
    {
        int maxscore = INT_MIN;
        string maxfood;
        for (auto &f : c2f[cuisine])
        {
            if (f2r[f] > maxscore)
            {
                maxscore = f2r[f];
                maxfood = f;
            }
            else if (f2r[f] == maxscore)
            {
                if (f < maxfood)
                    maxfood = f;
            }
        }
        return maxfood;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

//TLE-2
class FoodRatings
{
private:
    unordered_map<string, vector<string>> c2f;
    unordered_map<string, int> f2r;
    unordered_map<string, string> f2c;
    unordered_map<string, int> c2hr;
    unordered_map<string, string> c2hf;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        for (int i = 0; i < cuisines.size(); i++)
            c2hr[cuisines[i]] = INT_MIN;
        for (int i = 0; i < foods.size(); i++)
        {
            if (!c2f.count(cuisines[i]))
            {
                c2f[cuisines[i]] = {};
            }
            c2f[cuisines[i]].emplace_back(foods[i]);
            f2c[foods[i]] = cuisines[i];
            f2r[foods[i]] = ratings[i];
            // set max food for each cuisines
            if (ratings[i] > c2hr[cuisines[i]])
            {
                c2hr[cuisines[i]] = ratings[i];
                c2hf[cuisines[i]] = foods[i];
            }
            else if (ratings[i] == c2hr[cuisines[i]])
            {
                if (foods[i] < c2hf[cuisines[i]])
                    c2hf[cuisines[i]] = foods[i];
            }
        }
    }

    void changeRating(string food, int newRating)
    {
        f2r[food] = newRating;
        string cuisine = f2c[food];
        if (newRating > c2hr[cuisine])
        {
            c2hr[cuisine] = newRating;
            c2hf[cuisine] = food;
        }
        else if (newRating == c2hr[cuisine])
        {
            if (food < c2hf[cuisine])
                c2hf[cuisine] = food;
        }
        else if (newRating < c2hr[cuisine])
        {
            c2hr[cuisine] = INT_MIN;
            c2hf[cuisine] = " ";
            for (auto &f : c2f[cuisine])
            {
                if (f2r[f] > c2hr[cuisine])
                {
                    c2hr[cuisine] = f2r[f];
                    c2hf[cuisine] = f;
                }
                else if (f2r[f] == c2hr[cuisine])
                {
                    if (c2hf[cuisine] == " ")
                        c2hf[cuisine] = f;
                    else if (f < c2hf[cuisine])
                        c2hf[cuisine] = f;
                }
            }
        }
    }

    string highestRated(string cuisine)
    {
        return c2hf[cuisine];
    }
};