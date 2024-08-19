SET ENABLE_SEQSCAN TO OFF;
SELECT
    pizza_name, pizzeria.name AS pizzeria_name
FROM menu m
    JOIN pizzeria ON pizzeria_id = pizzeria.id;

EXPLAIN ANALYZE

SELECT
    pizza_name, pizzeria.name AS pizzeria_name
FROM menu m
    JOIN pizzeria ON pizzeria_id = pizzeria.id;