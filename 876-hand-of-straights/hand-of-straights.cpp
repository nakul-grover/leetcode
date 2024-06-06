class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%(groupSize)!=0){
            return false;
        }
        int n=hand.size();
        unordered_map<int,int>m;
        sort(hand.begin(),hand.end());
        int badIndex=-1;
        int count=0;
        int prev=-1;
        int ans=0;
        int i=0;
        while(i<n){
            if((count==0) || (hand[i]==prev+1 && m.find(i)==m.end())){
                prev=hand[i];
                count++;
                m[i]=1;
                cout<<i<<endl;
            }
            else if(badIndex==-1 && m.find(i)== m.end()){
                badIndex=i;
                cout<<badIndex<<"badIndex"<<i<<endl;
            }
            if(count==groupSize){
               count=0;
                cout<<count<<" "<<i<<""<<badIndex<<endl;
                if(badIndex!=-1){
                    i=badIndex;
                    badIndex=-1;
                    continue;
                }
            }
                i++;
            
            
        }
        if(count==0){
            return true;
        }
        return false;

        
    }
};