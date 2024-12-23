// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

// 使用rand7()实现rand10()

class Solution {
public:
    int rand10() {
        int t = (rand7() - 1) * 7 + rand7();
        if(t > 40) return rand10();

        return t % 10 + 1;
    }
};