class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> m;
        for (int i = 0; i < hand.size(); i++) {
            m[hand[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (auto i : m) {
            pq.push({i.first, i.second});
        }

        while (!pq.empty()) {
            vector<pair<int, int>> temp;
            int prev = -1;
            for (int i = 0; i < groupSize; i++) {
                if (!pq.empty()) {
                    pair<int, int> front = pq.top();
                    pq.pop();
                    if (prev != -1 && prev + 1 != front.first) {
                        return false;
                    }
                    prev = front.first;

                    front.second = front.second - 1;
                    temp.push_back(front);
                }
            }
            if(temp.size() != groupSize){
                return false;
            }
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i].second != 0) {
                    pq.push(temp[i]);
                }
            }
        }

        return true;
    }
};