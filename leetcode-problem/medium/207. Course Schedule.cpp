class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<int> outDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto& p : prerequisites) {
            inDegree[p[0]]++;
            outDegree[p[1]]++;
            adj[p[1]].push_back(p[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;
            for (int nextCourse : adj[course]) {
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        return count == numCourses;
    }
};