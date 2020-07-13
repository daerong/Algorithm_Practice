//link : https://www.hackerrank.com/challenges/weather-observation-station-3/problem?h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
//try : 3
//time : 10m
//비고 : 연산문제

//오답
select city from station
where id = (id%2 = 0);

//정답
select city from station
where MOD(id, 2) = 0
group by city;

//또는
select distinct(city) from station
where MOD(id, 2) = 0;
