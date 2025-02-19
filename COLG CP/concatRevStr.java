class concatRevStr {

    public static StringBuilder conRevString(String s1, String s2) {
        String s3 = s1 + s2;
        StringBuilder st = new StringBuilder();
        st.append(s3);
        st = st.reverse();
        return st;
    }

    public static void main(String[] args) {
        String s1 = "Hello";
        String s2 = "World";
        System.out.println(conRevString(s1, s2));
    }
}