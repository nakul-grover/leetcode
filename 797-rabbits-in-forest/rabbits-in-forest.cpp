class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>m;
        int count = 0;

        for(int i=0; i<answers.size(); i++){
            if(m.find(answers[i]+1) != m.end() && m[answers[i] + 1] < answers[i] + 1){
                m[answers[i] + 1]++;
            }
            else{
                m[answers[i] + 1] = 1;
            }
            if(m[answers[i] +1] == answers[i] +1){
                count = count + m[answers[i] +1 ];
                m.erase(answers[i] + 1);
            }
        }

        for(auto i : m){
            count += i.first;
        }

        return count;
    }                                                                                                                                                                                                       
};