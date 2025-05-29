class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0, j=0, k=0;
        string ans = "";
        while(i < word1.size() && j < word2.size()){
            if(k % 2 == 0){
                ans += word1[i];
                i++;
            }else{
                ans += word2[j];
                j++;
            }
            k++;
        }
        if(j == word2.size()){
            while(i < word1.size()){
                ans += word1[i];
                i++;
            }
        }
        if(i == word1.size()){
            while(j < word2.size()){
                ans += word2[j];
                j++;
            }
        }
        return ans;
    }
};