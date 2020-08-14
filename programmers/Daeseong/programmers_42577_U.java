//Solution
//- 글자수 작은 문자의 글자수에 맞춰서 String의 모든 성분이 일치하면 false를 아니면 true를 리턴

class Solution {
    public static boolean solution(String[] phone_book) {
        for(int one = 0; one < phone_book.length; one++){
            for(int two = 0; two < phone_book.length; two++){
                if(one == two) continue;
                int len = Math.min(phone_book[one].length(), phone_book[two].length());
                int i;
                for(i = 0; i < len; i++){
                    if(phone_book[one].charAt(i) != phone_book[two].charAt(i)) break;
                }
                if(i == len) return false;
            }
        }

        return true;
    }
}