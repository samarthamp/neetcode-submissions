class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // rows check
        bool valid = true;
        for (int i = 0; i < 9; i++)
        {
            vector<bool> hash(10, false);

            for (int j = 0; j < 9; j++)
            {
                char ele = board[i][j];
                if (ele == '.') continue;

                int num = ele - '0';
                if (hash[num])
                {
                    valid = false;
                    break;
                }
                hash[num] = true;
            }
            if (!valid) return valid;
        }

        if (!valid) return valid;

        // cols check
        for (int i = 0; i < 9; i++)
        {
            vector<bool> hash(10, false);

            for (int j = 0; j < 9; j++)
            {
                char ele = board[j][i];
                if (ele == '.') continue;

                int num = ele - '0';
                if (hash[num])
                {
                    valid = false;
                    break;
                }
                hash[num] = true;
            }
            if (!valid) return valid;
        }
        
        if (!valid) return valid;

        // sub-boxes check

        for (int k_i = 0; k_i < 3; k_i++)
        {
            for (int k_j = 0; k_j < 3; k_j++)
            {
                vector<bool> hash(10, false);

                for (int i = 3*k_i; i < 3*(k_i+1); i++)
                {
                    for (int j = 3*k_j; j < 3*(k_j+1); j++)
                    {                        
                        char ele = board[i][j];
                        if (ele == '.') continue;
                        
                        int num = ele - '0';
                        if (hash[num])
                        {
                            valid = false;
                            break;
                        }
                        hash[num] = true;
                    }
                    if (!valid) return valid;
                }
                if (!valid) return valid;
            }
            if (!valid) return valid;
        }
        return valid;
    }
};