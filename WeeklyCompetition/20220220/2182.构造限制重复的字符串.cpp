/*
 * @lc app=leetcode.cn id=2182 lang=cpp
 *
 * [2182] 构造限制重复的字符串
 */

// @lc code=start
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string res="";
        map<char,int> mp;
        
        for(int i=0;i<s.length();i++){
            if (mp.count(s[i]) == 0)
                mp.insert(make_pair(s[i],1));
            else
                mp[s[i]]++;
        }
        vector<char> keys;
        for(map<char,int>::iterator it = mp.begin(); it !=mp.end(); it++){
            keys.push_back(it->first);
        }
        sort(keys.begin(),keys.end());
        for(int i=keys.size()-1;i>=0;i--){
            int iter=0;
            while(mp[keys[i]]!=0){
                if(iter<repeatLimit && mp[keys[i]]>0){
                    res+=keys[i];
                    mp[keys[i]]--;
                    iter++;
                }
                else{
                    int offset=1;
                    while(i-offset>=0){
                        if(mp[keys[i-offset]]>0){
                            res+=keys[i-offset];
                            mp[keys[i-offset]]--;
                            iter=0;
                            break;
                        }
                        offset++;
                    }
                }
                //两种情况：
                //1. i==0 在最小的字符时，无法重复超过limit次
                //2. mp[keys[0]]==0 在其他字符时，最小的字符已经用完了
                if(iter==repeatLimit&&(i==0||mp[keys[0]]==0))
                    break;
            }
        }
       return res;
    }
};
// @lc code=end

//"xyutfpopdynbadwtvmxiemmusevduloxwvpkjioizvanetecnuqbqqdtrwrkgt"\n1
//"zyxyxwxwvwvuvuvututstrtrt"

//"bplpcfifosybmjxphbxdltxtfrjspgixoxzbpwrtkopepjxfooazjyosengdlvyfchqhqxznnhuuxhtbrojyhxwlsrklsryvmufoibgfyxgjw"\n1
//"zyzyzyxyxyxyxwxwxwxvxvxuxututststsrsrsrqrqrpopopopopopopononmnmlklkljljljijijijhghghghghfhfefefdfdfcfcbab"
//"zyzyzyxyxyxyxwxwxwxvxvxuxututststsrsrsrqrqrpopopopopopopononmnmlklkljljljijijijhghghghghfhfefefdfdfcfcbab"