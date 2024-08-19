SELECT
    pizzeria.name AS pizzeria_name
FROM pizzeria
    JOIN person_visits pv ON pizzeria.id = pv.pizzeria_id
    JOIN person ps ON pv.person_id = ps.id
WHERE
    ps.name = 'Andrey'
EXCEPT
SELECT pizzeria.name AS pizzeria_name
FROM menu
    INNER JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
    INNER JOIN person_order ON person_order.menu_id = menu.id
    JOIN person on person_order.person_id = person.id
WHERE person.name = 'Andrey';