SELECT
    piz.name AS pizzeria_name
FROM
    (
        SELECT
            id
        FROM
            person
        WHERE
            name = 'Dmitriy'
    ) AS ps
    JOIN person_visits pv ON ps.id = pv.person_id AND pv.visit_date = '2022-01-08'
    JOIN pizzeria piz ON pv.pizzeria_id = piz.id
    JOIN menu mn ON pv.pizzeria_id = mn.pizzeria_id AND mn.price < 800
ORDER BY
  pizza_name;