public class JumpGame {
    private static boolean helper(int[] array, int endPos)
    {
        boolean res = false;
        for(int i = 0; i < endPos; i++)
        {
            if(i + array[i] >= endPos)
            {
                if(i == 0) return true;

                 res = res || helper(array, i);
            }
        }
        return res;
    }

    public static boolean canWin(int[] array)
    {
        if(array.length == 1) return true;
        return helper(array, array.length-1);
    }
}
