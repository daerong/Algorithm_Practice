//link : https://www.hackerrank.com/challenges/ctci-queue-using-two-stacks/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=stacks-queues
//비고 : 
// 1. for문 안에서 pop을 썼기때문에 원인 디버깅에 시간이 많이 걸림
// 2. 스택끼리 오가는 작업이 시간 제한에 걸림 O(2N)

//기존 코드
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

//해결한 코드
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static class MyQueue<T> {
        Stack<T> stackIn = new Stack<T>();
        Stack<T> stackOut = new Stack<T>();

        //시간 제한 극복한 방법
        //1. enqueue를 할때마다 스택 쉬프팅이 발생하면 부하가 크다
        //2. 가만 보니 peek과 pop은 어짜피 뒤에서만 빼니까 stackOut에서 빼기만 하면 된다.
        //3. 즉 enqueue할때는 stackIn에 계속 쌓아놓다가 peek, pop 계산시 stackOut이 비었을때 옮기면된다

        public void enqueue(T value) { 
            stackIn.push(value);
        }

        public T peek() {                      
            //아래 for문은 한번씩 덜 돈다. 왜?
            //stackIn pop을 해버리니까 조건문의 size가 1개 감소하기 때문이다.
            // for(int i=0; i<stackIn.size(); i++){
            if(stackOut.empty()){
                while(!stackIn.empty()){
                    //아래 두줄을 한 줄로 쓸 수 있다.
                    // T temp = stackIn.pop();
                    // stackOut.push(temp);
                    stackOut.push(stackIn.pop());
                } 
            }
            return stackOut.peek();
        }

        public void dequeue() {
            //그냥 pop만 하면 안되고, out 스택은 비었으나 In 스택에 아직 쌓아놓고 있고 옮기지 않은 경우를 생각하자
            if(stackOut.empty()){
                while(!stackIn.empty()){
                stackOut.push(stackIn.pop());
                }
            }
            stackOut.pop();
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

