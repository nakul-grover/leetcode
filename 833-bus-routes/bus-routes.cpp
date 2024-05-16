
class Solution {
public:
    int numBusesToDestination(std::vector<std::vector<int>>& routes, int source, int target) {
        int n = routes.size();
        if (source == target) {
            return 0;
        }

        unordered_map<int, std::unordered_set<int>> stopToRoutes;
        for (int i = 0; i < n; ++i) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].insert(i);
            }
        }

        queue<std::pair<int, int>> q;
        q.push({source, 0});
        unordered_set<int> visitedStops;
        visitedStops.insert(source);

        while (!q.empty()) {
            int currentStop = q.front().first;
            int buses = q.front().second;
            q.pop();

            for (int route : stopToRoutes[currentStop]) {
                for (int nextStop : routes[route]) {
                    if (nextStop == target) {
                        return buses + 1;
                    }
                    if (visitedStops.find(nextStop) == visitedStops.end()) {
                        q.push({nextStop, buses + 1});
                        visitedStops.insert(nextStop);
                    }
                }
                routes[route].clear();
            }
        }
        
        return -1;  
    }
};
