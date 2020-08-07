import java.util.*;

class Solution {
    public static int[] solution(String[] genres, int[] plays) {
        Queue<Integer> q = new LinkedList<>();

        Vector<GENRE> vec = new Vector<>();


        for(int i = 0; i < genres.length; i++){
            int locate = -1;

            for(int n = 0; n < vec.size(); n++){
                if(vec.get(n).genre == genres[i]){
                    locate = n;
                    break;
                }
            }

            if(locate == -1){
                vec.addElement(new GENRE(genres[i], plays[i], i));
            }else{
                vec.get(locate).cnt += plays[i];
                vec.get(locate).pq.offer(new SONG(plays[i], i));
            }
        }

        Collections.sort(vec);

        for(int i = 0; i < vec.size(); i++){
            int index = 0;
            while (!vec.get(i).pq.isEmpty()){
                SONG temp = vec.get(i).pq.poll();
                if(index > 1) break;
                q.offer(temp.index);
                index++;
            }
        }

        int[] answer = new int[q.size()];

        int index = 0;
        while (!q.isEmpty()){
            int temp = q.poll();
            answer[index++] = temp;
        }

        return answer;
    }

    static class GENRE implements Comparable<GENRE>{
        String genre;
        int cnt;
        PriorityQueue<SONG> pq = new PriorityQueue<>();

        GENRE(String genre, int play, int index){
            this.genre = genre;
            this.cnt = play;
            pq.offer(new SONG(play, index));
        }

        @Override
        public int compareTo(GENRE target) {
            if(this.cnt > target.cnt) return -1;
            else if(this.cnt < target.cnt) return 1;
            return 0;
        }
    }

    static class SONG implements Comparable<SONG>{
        int play;
        int index;

        public SONG(int play, int index) {
            this.play = play;
            this.index = index;
        }

        @Override
        public int compareTo(SONG target) {
            if(this.play > target.play) return -1;
            else if(this.play < target.play) return 1;
            return 0;
        }
    }
}