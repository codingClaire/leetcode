#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int s = a + b;
    string s_str = to_string(s);
    if (s < 0)
    {
        for (int i = s_str.length() - 3; i >= 2; i -= 3)
            s_str.insert(i, ",");
    }
    else
    {
        for (int i = s_str.length() - 3; i >= 1; i -= 3)
            s_str.insert(i, ",");
    }
    cout << s_str << endl;
    return 0;
}