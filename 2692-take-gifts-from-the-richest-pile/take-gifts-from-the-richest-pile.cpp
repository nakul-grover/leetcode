class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long >pq;
        for(int i=0;i<gifts.size();i++){
            pq.push(gifts[i]);
        }
        long long ans=0;
        for(int i=0;i<k;i++){
            int x=pq.top();
            pq.pop();
            int y=sqrt(x);
            pq.push(y);
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        
        return ans;
    }
};