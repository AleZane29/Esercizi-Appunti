-- Restituire gli id delle date che hanno registrato una temperatura maggiore di ieri

-- Tabella Weather:
-- | id | recordDate | temperature |
-- | -- | ---------- | ----------- |
-- | 1  | 2015-01-01 | 10          |
-- | 2  | 2015-01-02 | 25          |
-- | 3  | 2015-01-03 | 20          |
-- | 4  | 2015-01-04 | 30          |

WITH CTE AS (
    SELECT 
        id, 
        temperature,
        recordDate,
        LAG(temperature ,1) OVER (ORDER BY recordDate) AS prv_temp,
        LAG(recordDate ,1) OVER (ORDER BY recordDate) AS prv_date
    FROM 
        Weather
)
SELECT 
    id
FROM 
    CTE
WHERE 
    prv_temp < temperature AND DATEDIFF(recordDate, prv_date)=1 
    -- Per T-SQL, DATEDIFF(day, prv_date, recordDate)=1


-- Molto più semplice con una cross join
SELECT w1.id
FROM Weather w1, Weather w2
WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1 AND w1.temperature > w2.temperature;