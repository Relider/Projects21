DROP VIEW IF EXISTS all_tour;
DROP table IF EXISTS nodes_name;

CREATE TABLE nodes_name (
    point1 char NOT NULL,
    point2 char NOT NULL,
    cost   int  NOT NULL
);

INSERT INTO nodes_name (point1, point2, cost)
VALUES ('a', 'b', 10),
       ('b', 'a', 10),
       ('a', 'c', 15),
       ('c', 'a', 15),
       ('c', 'b', 35),
       ('b', 'c', 35),
       ('a', 'd', 20),
       ('d', 'a', 20),
       ('c', 'd', 30),
       ('d', 'c', 30),
       ('d', 'b', 25),
       ('b', 'd', 25);
       
CREATE VIEW all_tour AS (
WITH RECURSIVE all_tour AS (
  SELECT point1::varchar as tour, point1, point2, cost, cost as sum FROM nodes_name
  WHERE point1 = 'a'  -- сделали первую букву, которая всегда а
  UNION SELECT 
              tmp.tour || ',' || tmp.point2 as tour, -- еще 1
              before_tmp.point1,
              before_tmp.point2,
              tmp.cost,
              tmp.sum + before_tmp.cost AS sum -- продолжаем сумму считать
  FROM nodes_name as before_tmp
  JOIN all_tour as tmp ON before_tmp.point1 = tmp.point2 -- ищем подходящую пару, чтобы города местами поменялись и можно было продолжать
  WHERE tour NOT LIKE '%' || tmp.point2 || '%' -- чтобы работало
)
  SELECT * FROM all_tour
);

SELECT sum as total_cost, '{' || tour || ',' || 'a}' as tour FROM all_tour
WHERE length(tour) = 7 AND sum = (SELECT min(sum) FROM all_tour WHERE length(tour) = 7)
ORDER BY total_cost, tour;