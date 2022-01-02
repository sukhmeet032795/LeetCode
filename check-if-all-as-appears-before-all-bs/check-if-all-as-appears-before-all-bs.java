class Solution {
    public boolean checkString(String s) {
        
        boolean check = false;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'b') {
                check = true;
            }
            
            if(check == true && s.charAt(i) == 'a')
                return false;
        }
        return true;
    }
}