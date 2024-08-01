class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans =0;
        for(int i=0;i<details.size();i++){
            string passenger = details[i];
            string age = passenger.substr(11,2);
            cout<<age<<endl;
            if(stoi(age)>60){
                ans++;
            }
        }
        return ans;
    }
};