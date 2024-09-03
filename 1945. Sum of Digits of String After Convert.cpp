class Solution {
public:
    int getLucky(string s, int k) {
        unordered_map<char,int>mpp;
        for(char c='a';c<='z';c++){
            mpp[c]=c-'a'+1;
        }
       string numStr;
        for(char c:s) {
            numStr+=to_string(mpp[c]); 
        }
       
        while(k!=0){
            int sum=0;
            for (char c:numStr) {
                sum+=c - '0'; 
            }
                numStr=to_string(sum);
            k--;
        }
        return stoi(numStr);
    }
};