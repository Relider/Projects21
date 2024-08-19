SELECT
    mn.pizza_name,
    mn.price,
    piz.name AS pizzeria_name,
    pv.visit_date
FROM
    pizzeria piz
    JOIN menu mn ON piz.id = mn.pizzeria_id
    JOIN person_visits pv ON piz.id = pv.pizzeria_id
    JOIN person ps ON pv.person_id = ps.id
WHERE
    ps.name = 'Kate' AND
    mn.price BETWEEN 800 AND 1000
ORDER BY
    pizza_name, price, pizzeria_name;