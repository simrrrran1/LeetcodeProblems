class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>>  v = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
        string s = "";

        for(int i=12; i>=0; i--){
            int val = v[i].first;
            string s1 = v[i].second;
            while(num >= val){
                s += s1;
                num -= val;
            }
        }
        return s;
    }
};