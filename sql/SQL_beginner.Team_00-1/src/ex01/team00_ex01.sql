DROP VIEW IF EXISTS view_all_tour;

CREATE VIEW view_all_tour AS (
WITH RECURSIVE all_tour AS (
  SELECT point1::varchar as tour, point1, point2, cost, cost as summ FROM nodes_name
  WHERE point1 = 'a'  -- сделали первую букву, которая всегда а
  UNION SELECT 
              tmp.tour || ',' || tmp.point2 as tour, -- еще 1
              before_tmp.point1,
              before_tmp.point2,
              tmp.cost,
              tmp.summ + before_tmp.cost AS summ -- продолжаем сумму считать
  FROM nodes_name as before_tmp
  INNER JOIN all_tour as tmp ON before_tmp.point1 = tmp.point2 -- ищем подходящую пару, чтобы города местами поменялись и можно было продолжать
  WHERE tour NOT LIKE '%' || tmp.point2 || '%' -- чтобы работало
)
SELECT '{' || tour || ',' || point2 || '}' AS traces, summ
FROM all_tour
WHERE length(tour) = 7
  and point2 = 'a'
ORDER BY summ);

SELECT summ as total_cost, traces as tour
FROM view_all_tour
ORDER BY total_cost, tour;