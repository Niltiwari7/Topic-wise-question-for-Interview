class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stud;
        for(int s : students)
            stud.push(s);

        stack<int> sand;
        for(int i = sandwiches.size() - 1; i >= 0; i--)
            sand.push(sandwiches[i]);

        int repeat = 0;
        int eaten = 0;
        int n = students.size();
        while (!sand.empty() && !stud.empty()) {
            if (sand.top() == stud.front()) {
                sand.pop();
                stud.pop();
                eaten++;
                repeat = 0;
            } else {
                int temp = stud.front();
                stud.pop();
                stud.push(temp);
                repeat++;
            }

            // If all remaining students' preferences don't match any sandwiches,
            // break the loop to avoid infinite loop
            if (repeat == stud.size())
                break;
        }
        return n - eaten;
    }
};
