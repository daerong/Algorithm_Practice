//link : https://www.hackerrank.com/challenges/weather-observation-station-5/problem
//try : 4
//비고 : MIN, MAX, Order by, Group by의 고민.. 해답은 LIMIT

select city, length(city) from station order by length(city), city LIMIT 1;
select city, length(city) from station order by length(city) desc, city LIMIT 1;

