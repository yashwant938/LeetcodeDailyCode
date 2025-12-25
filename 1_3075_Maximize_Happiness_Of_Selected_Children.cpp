class Solution {
public:
//Havel Hakimi kind of approach
    long long maximumHappinessSum(vector<int>& happiness, int k) {
       priority_queue<int>pq;
       for(auto it:happiness){
        pq.push(it);
       }
       long long total=0;
       int turns=0;

       while(k--&&!pq.empty()){
        int top=pq.top();
        pq.pop();
        int cur=top-turns;
        if(cur<=0)  break;
        total+=cur;
        turns++;

       }
       return total;
    }
};
