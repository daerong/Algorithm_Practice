

## Greedy Method

**탐욕 알고리즘이란?**  
그 순간에 최적인 것을 선택하는 방식으로 최적해를 구하는 기법입니다.  
여러 경우 중 하나를 결정해야 할 때, 그 순간에 최적이라고 생각되는 것을 선택해 나가는 방식  

**탐욕 알고리즘의 특징**  
순간의 선택 지역적으로 최적이지만 최종적(전역적)인 해답이 최적이라는 보장은 없다.  
탐욕 알고리즘이 잘 작동하는 문제는 greedy choice property와 optimal substructure 두 가지 속성을 만족합니다.  

> **Greedy Choice Property**  
> 앞의 선택이 이후 선택에 영향을 주지 않는다는 걸 의미합니다.  

> **Optimal Substructure**  
> 문제 전체에 대한 최적해(global optimum)가 부분문제에 대해서도 역시 최적해가 된다는 걸 뜻합니다.  
> 즉, 지역적으로 최적이면서 전역적으로도 최적이 됩니다.  

**예시**  
- Activity-Selection Problem  
- Huffman Coding  

>**Activity-Selection Problem**  
> classroom assignment(교실할당)로도 불리는 한정된 교실에서 최대 수업을 배정하는 문제  
> 시간 복잡도는 O(n)  
	
> **Huffman Coding**  
> 허프만 코딩이란 Greedy Method을 사용해 데이터를 압축하는 기법  
> 시간 복잡도는 O(nlog n)  

참고문서  
[https://ratsgo.github.io/data%20structure&algorithm/2017/11/22/greedy/](https://ratsgo.github.io/data%20structure&algorithm/2017/11/22/greedy/)

## Kruskal's Algorithm (MST)  

**크루스칼이란?**  
Spanning Tree의 합을 최소로 하는 MST(Minimal Spanning Tree)를 만들기 위한 방법이다.  
탐욕적인 방법(Greedy Method) 을 이용한다.  

>**Spanning Tree(스패닝 트리)**  
>방향이 없는 그래프에서 모든 Node를 포함하면서 Cycle을 이루지 않는 경우 Spanning Tree라고 한다.  

> **MST(Minimal Spanning Tree, 최소 비용 신장 트리)**  
>1. Spanning Tree 조건을 충족  
>2. Edge의 합이 최소  

>**Greedy Method**  
>- 결정을 해야 할 때마다 그 순간에 가장 좋다고 생각되는 것을 선택함으로써 최종적인 해답에 도달하는 것  
>- 탐욕적인 방법은 그 순간에는 최적이지만, 전체적인 관점에서 최적이라는 보장이 없기 때문에 반드시 검증해야 한다.  
>- 다행히 Kruskal 알고리즘은 최적의 해답을 주는 것으로 증명되어 있다.  

**[크루스칼의 동작](https://ko.wikipedia.org/wiki/%ED%81%AC%EB%9F%AC%EC%8A%A4%EC%BB%AC_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)**  
1. Graph의 Edge들을 가중치의 오름차순으로 정렬한다.  
2. 가중치가 가장 작은 Edge을 선택한다.  
	Cycle을 만드는 경우 무시한다.  
3. 두개의 Node를 서로 연결한다.  
	Edge가 이미 형성된 경우 무시한다.  
4. 위 과정을 반복한다.  

>**Graph**  
>그래프는 Vertex라고 불리는 정점(Node)과, Edge로 불리는 간선들의 조합으로 이루어져있다.  

>**주의사항**  
>- 새로운 Edge가 이미 연결되어 있는 Node들에 연결될 때 Cycle이 형성된다.  
>	- 즉, 추가할 Edge의 양 Node가 같은 집합에 속해 있으면 Cycle이 형성된다.  
>- Cycle 생성 여부를 확인하는 방법  
>	- 추가하고자 하는 Edge의 양끝 Node가 같은 집합에 속해 있는지를 먼저 검사해야 한다.  
>	- 'union-find 알고리즘' 이용  

**크루스칼의 시간 복잡도**  
- O(Elog N)
	- Edge 정렬 : O(Elog E)
	- Union-FInd : O(Elog N)
	-  O(Nlog N + Elog N) = O(Elog N)

예제  
[SW Expert Acdemy 1251번](https://github.com/daerong/Algorithm_Practice/blob/master/swea/Daeseong/swea_1251_U.cpp)  
	
참고문서  
[https://ko.wikipedia.org/wiki/%ED%81%AC%EB%9F%AC%EC%8A%A4%EC%BB%AC_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98](https://ko.wikipedia.org/wiki/%ED%81%AC%EB%9F%AC%EC%8A%A4%EC%BB%AC_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)  
[https://gmlwjd9405.github.io/2018/08/29/algorithm-kruskal-mst.html](https://gmlwjd9405.github.io/2018/08/29/algorithm-kruskal-mst.html)  
[https://yabmoons.tistory.com/186](https://yabmoons.tistory.com/186)  

## Prim's Algorithm (MST)  

**프림 알고리즘이란?**  
Kruskal Algorithm과 같은 MST(Minimal Spanning Tree)를 만들기 위한 방법이다.
탐욕적인 방법(Greedy Method)을 이용한다.  

>**Spanning Tree(스패닝 트리)**  
>방향이 없는 그래프에서 모든 Node를 포함하면서 Cycle을 이루지 않는 경우 Spanning Tree라고 한다.  

> **MST(Minimal Spanning Tree, 최소 비용 신장 트리)**  
>1. Spanning Tree 조건을 충족  
>2. Edge의 합이 최소  

>**Greedy Method**  
>- 결정을 해야 할 때마다 그 순간에 가장 좋다고 생각되는 것을 선택함으로써 최종적인 해답에 도달하는 것  
>- 탐욕적인 방법은 그 순간에는 최적이지만, 전체적인 관점에서 최적이라는 보장이 없기 때문에 반드시 검증해야 한다.  
>- 다행히 Kruskal 알고리즘은 최적의 해답을 주는 것으로 증명되어 있다.  

**[프림 알고리즘의 동작](https://ko.wikipedia.org/wiki/%ED%94%84%EB%A6%BC_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)**  
1. Graph의 한 Node를 선택한다.  
2. Node에 연결된 가중치가 가장 작은 Edge를 선택한다.  
3. 연결된 Node들과 연결된 가중치가 가장 작은 Edge를 선택한다.  
	새로운 Edge는 새로운 Node에 연결된다. 
4. 2로 돌아가 반복한다.  
	모든 정점이 연결될 때까지 반복한다.  

**크루스칼 vs 프림 비교**  
크루스칼과 프림 모두 가중치가 낮은 간선(Edge)을 선택한다. 즉, 순간의 최선을 선택하는 Greedy Method를 이용한다.  
| Kruskal| Prim |
|--|--|
| 크루스칼의 경우에는 간선(Edge)의 가중치를 오름차순으로 정렬한 뒤, 순차적으로 선택하여 MST를 만든다. | 프림의 경우에는 양 끝단의 Node(정점)을 통해 가중치가 낮은 간선을 이어붙이며 MST를 만든다. |

**프림의 시간 복잡도**   
- O(Elog N)  
	- Extract-Min : O(Nlog N)  
	- Search and Decrease-Key : O(Elog N)  
	- O(Nlog N + Elog N) = O(Elog N)  
- O(E + logN)  
	- 피보나치 힙 사용 시 

>**Extract-Min**  
>Extract-Min : 가장 작은 요소를 반환한 후, 삭제한다.  
>Extract-Max : 가장 큰 요소를 반환한 후, 삭제한다.  

>**Search and Decrease-Key**  
>Search : 트리의 길이(Node 수)만큼 탐색(O(log N))해야한다.  
>Decrease-Key : 모든 Node에 대해 Edge 가중치 업데이트(O(E/Vlog V))가 실행되므로 O(E logV)의 시간복잡도를 갖는다.  

>**Fibonacci heap(피보나치 힙)**  
>우선순위 큐(priority queue) 연산을 위한 자료 구조로, 힙-정렬된 트리를 모아놓은 자료 구조이다.  
>힙이 결합하는 과정이 피보나치 수열과 유사하여 피보나치 힙으로 불린다. 

예제  
[SW Expert Acdemy 3124번](https://github.com/daerong/Algorithm_Practice/blob/master/swea/Daeseong/swea_3124_U.cpp)  

참고문서  
[https://ko.wikipedia.org/wiki/%ED%94%84%EB%A6%BC_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98](https://ko.wikipedia.org/wiki/%ED%94%84%EB%A6%BC_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)  
[https://m.blog.naver.com/PostView.nhn?blogId=kimmy5000&logNo=220635475967&proxyReferer=https:%2F%2Fwww.google.com%2F](https://m.blog.naver.com/PostView.nhn?blogId=kimmy5000&logNo=220635475967&proxyReferer=https:%2F%2Fwww.google.com%2F)  
[https://www.cs.auckland.ac.nz/software/AlgAnim/prim.html](https://www.cs.auckland.ac.nz/software/AlgAnim/prim.html)  
[https://journee912.tistory.com/67](https://journee912.tistory.com/67)   
