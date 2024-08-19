SELECT
    DISTINCT ps.name
FROM
    person ps
    JOIN person_order po ON ps.id = po.person_id
    JOIN menu mn ON po.menu_id = mn.id
WHERE
    ps.address IN ('Moscow', 'Samara') AND
    ps.gender = 'male' AND
    mn.pizza_name IN ('pepperoni pizza', 'mushroom pizza')
ORDER BY
    ps.name DESC;