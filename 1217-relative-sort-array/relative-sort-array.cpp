class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        vector<int>res;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
        for(int i=0;i<arr2.size();i++){
            while(mp[arr2[i]]>0){
                res.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
            mp.erase(arr2[i]);
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            while(it->second>0){
                res.push_back(it->first);
                it->second--;
            }
            mp.erase(it->first);
        }
        return res;
    }
};