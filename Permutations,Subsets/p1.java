class p1 {
    public static String removeApple(String s, String r) {
        if(s.isEmpty()) return "";
        
        if(s.startsWith(r)) {
            return removeApple(s.substring(r.length()), r);
        }
        else {
            return s.charAt(0) + removeApple(s.substring(1), r);
        }
    }

    public static void main(String[] args) {
        String s = "poapplepo";
        System.out.print(removeApple(s, "apple"));
    }
}