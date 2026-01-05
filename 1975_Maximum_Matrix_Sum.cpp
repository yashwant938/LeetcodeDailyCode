class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long tSum=0;
        int neg=0;
        int minAb=INT_MAX;
        for(auto &row:matrix){
            for(int v:row){
                if(v<0) neg++;
                int a=abs(v);
                tSum+=a;
                minAb=min(minAb,a);
            }
        }
        return (neg%2==0) ?tSum:tSum-2LL*minAb;
    }
};