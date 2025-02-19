public class changeTheString {
    
    public static String cngeStr(String s) {
        char temp = s.charAt(0);
        boolean flag = false; // false for lower case, true for upper case
        
        if(Character.isLowerCase(temp)) flag = false;
        else flag = true;

        if(flag) s = s.toUpperCase();
        else s = s.toLowerCase();
        return s;
    }

    public static void main(String[] args) {
        String s = "Lello";
        System.out.println(cngeStr(s));
    }
}
