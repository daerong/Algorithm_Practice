//link : https://www.hackerrank.com/challenges/ctci-queue-using-two-stacks/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=stacks-queues
//비고 : 
// 1. for문 안에서 pop을 썼기때문에 원인 디버깅에 시간이 많이 걸림
// 2. 스택끼리 오가는 작업이 시간 제한에 걸림 O(2N)

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static class MyQueue<T> {
        Stack<T> stackNewestOnTop = new Stack<T>();
        Stack<T> stackOldestOnTop = new Stack<T>();

        public void enqueue(T value) { // Push onto newest stack
            while(!stackOldestOnTop.empty()){
                T temp = stackOldestOnTop.pop();
                stackNewestOnTop.push(temp);
            }
            stackNewestOnTop.push(value);
            
            //아래 for문은 한번씩 덜 돈다. 왜?
            //stackNewestOnTop에서 pop을 해버리니까 조건문의 size가 1개 감소하기 때문이다.
            //1. 조건을 empty()로 바꾸는게 맞다.
            //2. peek를 써서 값을 이동시키면 나중에 또 N번 반복해서 POP을 해야한다.
            // for(int i=0; i<stackNewestOnTop.size(); i++){
            while(!stackNewestOnTop.empty()){
                T temp = stackNewestOnTop.pop();
                stackOldestOnTop.push(temp);
            }
        }

        public T peek() {
             return stackOldestOnTop.peek();
             //프린트문이 아니라 리턴을 써줘야함
        }

        public void dequeue() {
             stackOldestOnTop.pop();
            //그냥 팝이 아니라 리턴을 써줘야함

        }
    }

    
    public static void main(String[] args) {
        MyQueue<Integer> queue = new MyQueue<Integer>();
        
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        
        for (int i = 0; i < n; i++) {
            int operation = scan.nextInt();
            if (operation == 1) { // enqueue
                queue.enqueue(scan.nextInt());
            } else if (operation == 2) { // dequeue
                queue.dequeue();
            } else if (operation == 3) { // print/peek
                System.out.println(queue.peek());
            }
        }
        scan.close();
    }
}
