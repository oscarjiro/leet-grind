public class Solution 
{
    public long ColoredCells(int n) 
    {
        return 1 + 2 * (long)n * (n - 1);  
    }
}