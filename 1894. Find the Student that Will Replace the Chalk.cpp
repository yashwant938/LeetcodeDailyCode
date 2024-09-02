class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // if((k%sum)==0){
        //     return 0;
        // }else if((k%sum)>0){
        //     for(int i=0;i<chalk.size();k++){
        //         k=k-chalk[i];
        //         if(k<=0){
        //             return i;
        //         }else if(k<0){
        //             return i-1;
        //         }
        //     }
        // }
        // return 0;
        long long sum=accumulate(chalk.begin(),chalk.end(),0LL);
        k%=sum;
        for(int i=0;i<chalk.size();i++){
            k-=chalk[i];
            if(k<0){
                return i;
            }
        }
        return 0;
    }
};