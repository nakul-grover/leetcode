vector<int>m;
    bool sorter(int a,int b){
        string num1=to_string(a);
        string num2=to_string(b);
        for(int i=0;i<num1.size();i++){
            num1[i]=(m[num1[i]-'0'])+'0';
            // str1+=m[num1[i]];
            // cout<<m[num1[i]];
            
        }
        
        for(int i=0;i<num2.size();i++){
            num2[i]=(m[num2[i]-'0'])+'0';
            // str2+=m[num2[i]];
            
        }
        // cout<<endl;
        int x=stoi(num1);
        int y=stoi(num2);
        return x<y;
        
}
class Solution {
public:

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
//         vector<int>store;
//         vector
//         unordered_map<int,int>m;
//         for(int i=0;i<mapping.size();i++){
//             m[i]=mapping[i];
//         }
//         for(auto i:nums){
//             string s=to_string(nums[i]);
//             for(int i=0;i<s.size();i++){
//                 s[i]=m[s[i]];
//             }
//             int x=stoi(s);
//             ans.push_back(x);
//         }
        
//         return ans;
        m=mapping;
        sort(nums.begin(),nums.end(),sorter);
        return nums;
        
    }
};