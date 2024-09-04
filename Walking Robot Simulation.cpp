class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        int max = Integer.MIN_VALUE;
        int[] curr = {0, 1};
        int[] ans = {0, 0};
        Set<List<Integer>> set = new HashSet<>();
        for (int[] obstacle : obstacles) {
            set.add(Arrays.asList(obstacle[0], obstacle[1]));
        }

        for (int command : commands) {
            if (command < 0)
               curr = getDirection(command, curr);
            else {
                while (command-- > 0) {
                    ans[0] += curr[0];
                    ans[1] += curr[1];
                    if (set.contains(Arrays.asList(ans[0], ans[1]))) {
                       ans[0] -= curr[0];
                       ans[1] -= curr[1];
                       break;
                    }
                }
                max = Math.max(max, (ans[0]*ans[0]) + (ans[1]*ans[1]));
            }
        }
        return max;
    }
    private int[] getDirection(int dir, int[] curr) {
        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int i = 0;
        for (int j = 0; j < 4; ++j) {
            if (Arrays.equals(curr, directions[j])) {
               i = j;
               break;
            }
        }
        if (dir == -1)
           return directions[(i + 1) % 4];
        return directions[(i - 1 + 4) % 4];
    }
}