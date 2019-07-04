/*
判断一个数字是否是2的幂次方
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return fabs((int)(log(n)/log(2))-(log(n)/log(2)))<10e-10;
    }
};