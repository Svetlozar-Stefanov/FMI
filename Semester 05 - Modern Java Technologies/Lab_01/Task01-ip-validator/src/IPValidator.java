public class IPValidator {
    public static boolean validateIPv4Address(String str)
    {
        String[] octets = str.split("\\.");
        if(octets.length != 4)
        {
            return false;
        }

        for(String octet : octets)
        {
            int len = octet.length();
            if (len < 1 || len > 3) return false;
            if (len > 1 && octet.charAt(0) == '0') return false;
            for(int i = 0; i < len; i++)
            {
                if(!Character.isDigit(octet.charAt(i))) return false;
            }
            int num = Integer.parseInt(octet);
            if (num < 0 || num > 255) return false;
        }
        return true;
    }
}
