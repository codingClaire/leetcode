class RangeFreqQuery {
public:
    unordered_map<int,vector<int>> rangemap; //用unordered_map比map的速度更快
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            rangemap[arr[i]].emplace_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        auto l=lower_bound(rangemap[value].begin(),rangemap[value].end(),left);
        auto r=upper_bound(rangemap[value].begin(),rangemap[value].end(),right);
        return distance(l,r);
    }
};
/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

//我比赛的写法 TLE了
/*class RangeFreqQuery {
public:
    vector<int> data;
    map<int,map<int,int>> num;
    RangeFreqQuery(vector<int>& arr) {
        //this->data.assign(arr.begin(),arr.end());
        map<int,int> numpair; //arr[i]-number
        for(int i=0;i<arr.size();i++){
            if(numpair.find(arr[i])==numpair.end())
                numpair.insert(make_pair(arr[i],0));
            numpair[arr[i]]++;
            num.insert(make_pair(i,numpair));  //index-(arr[i]-number)
        }
    }
    
    int query(int left, int right, int value) {
        if(num[right].find(value)==num[right].end())
            return 0;
        if(num[left].find(value)==num[left].end())
            return num[right][value];
        return num[right][value]-num[left-1][value];
    }
};*/