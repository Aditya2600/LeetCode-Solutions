class Solution {
public:
    int MOD = 1e9 + 7;
    int state_mem[1002][1023];
    int countWays(int &m, int &n, int r, int c, int curr_state, int prev_state){
        if(c == n) return 1;
        if(r == m) return countWays(m, n, 0, c+1, 0, curr_state);
        if(r == 0 && state_mem[c][prev_state] != -1) return state_mem[c][prev_state];

        int up_color = 0;
        if(r>0) up_color = curr_state & 3;

        int left_color = (prev_state >> ((m - r - 1)*2)) & 3;
        int ways_to_color = 0;
        for(int color = 1; color<=3; ++color){
            if(color != up_color && color != left_color){
                ways_to_color = (ways_to_color + countWays(m, n, r+1, c, (curr_state << 2) + color, prev_state))%MOD;    
            }
        }
        if(r == 0){
            state_mem[c][prev_state] = ways_to_color;
        }
        return ways_to_color;
    }
    int colorTheGrid(int m, int n) {
        memset(state_mem, -1, sizeof(state_mem));
        return countWays(m, n, 0, 0, 0, 0);
    }
};