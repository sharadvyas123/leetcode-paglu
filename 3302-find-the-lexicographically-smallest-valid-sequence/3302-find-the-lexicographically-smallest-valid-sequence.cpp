class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<int> last(m, -1);
        
        int ptr = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            while (ptr >= 0 && word1[ptr] != word2[j]) {
                ptr--;
            }
            if (ptr >= 0) {
                last[j] = ptr;
                ptr--;
            }
        }

        vector<int> result;
        bool changed = false;
        int word1_idx = 0;

        for (int word2_idx = 0; word2_idx < m; ++word2_idx) {
            bool found = false;

            while (word1_idx < n) {
                if (word1[word1_idx] == word2[word2_idx]) {
                    result.push_back(word1_idx);
                    word1_idx++;
                    found = true;
                    break;
                }

                if (!changed) {

                    if (word2_idx == m - 1 || (last[word2_idx + 1] > word1_idx)) {
                        result.push_back(word1_idx);
                        word1_idx++;
                        changed = true;
                        found = true;
                        break;
                    }
                }

                word1_idx++;
            }

            if (!found) {
                return {};
            }
        }

        return result;
    }
};