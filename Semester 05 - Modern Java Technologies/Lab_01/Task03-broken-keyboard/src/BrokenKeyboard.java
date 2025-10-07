public class BrokenKeyboard {
    public static int calculateFullyTypedWords(String message, String brokenKeys)
    {
        boolean[] keys = new boolean[65535];
        for (int i = 0; i < brokenKeys.length(); i++)
        {
            keys[brokenKeys.charAt(i)] = true;
        }

        int counter = 0;
        for(var word : message.split("\\s+"))
        {
            if(word == "" || word == "\t") continue;
            boolean canBeWritten = true;
            for (int i = 0; i < word.length(); i++)
            {
                if (keys[word.charAt(i)])
                {
                    canBeWritten = false;
                    break;
                }
            }
            if(canBeWritten) counter++;
        }
        return counter;
    }
}
