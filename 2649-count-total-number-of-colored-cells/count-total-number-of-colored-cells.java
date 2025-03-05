class Solution {
    public long coloredCells(int n) {
        return 1 + 2 * (long)n * (n - 1);  
    }
}