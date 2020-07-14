//link : https://www.hackerrank.com/challenges/weather-observation-station-4/problem?h_r=next-challenge&h_v=zen
//try : 3
//time : 20
//비고 : SET

//실패
SELECT count(city)
FROM STATION
group by city
//1
//1
//1
//1
//...

//성공
//처음으로 SET @을 알게되었다.
SET @A = (
    select count(city) 
    from station);
    
SET @B = (
    select count(distinct(city)) 
    from station);

SELECT @A-@B;
