// class Solution {
// public:
//     bool check(int num, int sum){
//         int cnt=0;
//         for(int i=1;i<=num;i++){
//             if(i%num==0){
//                 sum+=i;
//                 cnt++;
//             }
//         }
//         if(cnt==4){
//             return sum;
//         }
//         return 0;
//     }
//     int sumFourDivisors(vector<int>& nums) {
//         for(int i=1;i<nums.size();i++){
//            int sum=0;
//             if(check(nums[i],sum)){
//                 return  sum; 
//             }
//         }
//         return 0;
//     }
// };

class Solution {
public:
    int getSumIfFourDivisors(int num) {
        int cnt = 0;
        int sum = 0;

        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                int d1 = i;
                int d2 = num / i;

                if (d1 == d2) {
                    cnt++;
                    sum += d1;
                } else {
                    cnt += 2;
                    sum += d1 + d2;
                }

                if (cnt > 4) return 0;
            }
        }

        return (cnt == 4) ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            ans += getSumIfFourDivisors(num);
        }
        return ans;
    }
};