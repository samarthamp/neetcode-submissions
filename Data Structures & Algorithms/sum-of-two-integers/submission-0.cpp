class Solution {
public:
    int getSum(int a, int b) {
        
        bool cin = 0;
        int sum = 0;
        for (int i = 0; i < 32; i++)
        {
            bool a_bit = a % 2;
            bool b_bit = b % 2;
            bool sum_bit = (a_bit ^ b_bit) ^ cin;
            cin = (a_bit && b_bit) || (cin && (a_bit ^ b_bit));

            if (sum_bit) sum |= (1U << i);
            a = a >> 1;
            b = b >> 1;
        }

        return sum;
    }
};