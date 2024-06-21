class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)return false;
        map<int,int> m;
        for(int i=0; i<hand.size(); i++){
            m[hand[i]]++;
        }
        int start = 0;
        int curr;
        while(m.size()>0){
            curr = m.begin()->first;
            for(int i=0; i<groupSize; i++){
                if(m[curr+i] == 0)return false;
                --m[curr+i];
                if(m[curr+i] == 0)m.erase(curr+i);
            }
        }
        return true;
    }
};