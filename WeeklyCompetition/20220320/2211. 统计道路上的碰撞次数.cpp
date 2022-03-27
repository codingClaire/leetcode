class Solution
{
public:
    int countCollisions(string directions)
    {
        int res = 0;
        stack<char> st; //栈模拟
        for (int i = 0; i < directions.size(); i++)
        {
            if (directions[i] == 'R')
            {
                st.push(directions[i]);
            }
            else if (directions[i] == 'L')
            {
                if (st.size() == 0)
                    continue;
                else if (st.top() == 'R')
                { //当前栈内有多个R
                    int flag = false;
                    while (!st.empty() && st.top() == 'R')
                    {
                        if (flag == false)
                        {
                            flag = true;
                            st.pop(); // pop R
                            res += 2;
                        }
                        else
                        {
                            st.pop();
                            res++;
                        }
                    }
                    st.push('S'); // push origin L
                }
                else if (st.top() == 'S')
                {
                    res++;
                }
            }
            else
            { // directions[i]=='S'
                if (st.size() == 0)
                    st.push(directions[i]); // push S
                else if (st.top() == 'R')
                { //当前栈内有多个R
                    while (!st.empty() && st.top() == 'R')
                    {
                        st.pop();
                        res++;
                    }
                    st.push(directions[i]); // push S
                }
                else
                {
                    st.push(directions[i]); // push S
                }
            }
        }
        return res;
    }
};


/* TLE解法
class Solution
{
public:
    bool isStatic(string d)
    {
        for (int i = 0; i < d.length() - 1; i++)
        {
            if (d[i] == 'R' && (d[i + 1] == 'L' || d[i + 1] == 'S'))
                return false;
            if (d[i] == 'S' && d[i + 1] == 'L')
                return false;
        }
        return true;
    }

    int countCollisions(string directions)
    {
        int res = 0;
        while (isStatic(directions) == false)
        {
            for (int i = 0; i < directions.length() - 1; i++)
            {
                if (directions[i] == 'R' && directions[i + 1] == 'L')
                {
                    directions[i] = 'S';
                    directions[i + 1] = 'S';
                    res += 2;
                }
                if (directions[i] == 'R' && directions[i + 1] == 'S')
                {
                    directions[i] = 'S';
                    directions[i + 1] = 'S';
                    res++;
                }
                if (directions[i] == 'S' && directions[i + 1] == 'L')
                {
                    directions[i] = 'S';
                    directions[i + 1] = 'S';
                    res++;
                }
            }
        }

        return res;
    }
};
*/