//linke : https://www.hackerrank.com/challenges/weather-observation-station-6/problem?h_r=next-challenge&h_v=zen
//try : 3

//
//substr(str, from, len)
//문자열의 시작점인 from은 0부터 시작하지 않고 1부터 시작한다.
//'같다'비교는 ==가 아닌 단일 = 만 사용한다.

select city from station where 
substr(city, 1, 1) = 'A' OR
substr(city, 1, 1) = 'E' OR
substr(city, 1, 1) = 'I' OR
substr(city, 1, 1) = 'O' OR
substr(city, 1, 1) = 'U'
group by city
