class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int countZero = 0, countOnes = 0;
        for(int i: students){
            if(i == 0) countZero++;
            if(i == 1) countOnes++;
        }

        for(int i: sandwiches){
            if(i == 0){
                if(countZero == 0) return countOnes;
                countZero--;
            } 
            if(i == 1) {
                if(countOnes == 0) return countZero;
                countOnes--;
            }
        }

        return 0;
    }
};