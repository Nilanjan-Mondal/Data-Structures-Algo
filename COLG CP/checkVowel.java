public class checkVowel {
    public static String checkV(char a) {
        String vowels = "aeiouAEIOU";
        if (vowels.indexOf(a) == -1) return "No";
        return "Yes";
    }

    public static void main(String[] args) {
        char s = 'f';
        System.out.println(checkV(s));
    }
}
