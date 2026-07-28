class Solution {
public:
    void Collision(int i, stack<int> &st, vector<int> &asteroids) {
        if (st.empty()) {
            st.push(asteroids[i]);
            return;
        }

        if (asteroids[i] > 0 && st.top() < 0) {

            if (asteroids[i] > abs(st.top())) {
                st.pop();

                if (st.empty()) {
                    st.push(asteroids[i]);
                } else {
                    Collision(i, st, asteroids);
                }
            }
            else if (asteroids[i] == abs(st.top())) {
                st.pop();
            }
            else {
                return;
            }
        }
        else {
            st.push(asteroids[i]);
        }
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        stack<int> st;
        int i = n - 1;
        while (i >= 0) {
            Collision(i, st, asteroids);
            i--;
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};