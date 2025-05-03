class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            for (int x = 1; x <= 6; x++) {
                int rotA = 0, rotB = 0;
                bool possible = true;
                for (int i = 0; i < size(tops); i++) {
                    if (tops[i] != x && bottoms[i] != x) {
                        possible = false;
                        break;
                    }
                    if (tops[i] != x) {
                        rotA++;
                    }
                    if (bottoms[i] != x) {
                        rotB++;
                    }
                }
                if (possible) {
                    return min(rotA, rotB);
                }
            }
            return -1;
        }
    };