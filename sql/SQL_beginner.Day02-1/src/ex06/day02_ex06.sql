SELECT
    mn.pizza_name,
    piz.name AS pizzeria_name
FROM
    (
    SELECT
      id,
      name
    FROM
      person
    WHERE
      name IN ('Anna', 'Denis')
  ) as ps
  JOIN person_order AS po ON po.person_id = ps.id
  JOIN menu AS mn ON mn.id = po.menu_id
  JOIN pizzeria AS piz ON piz.id = mn.pizzeria_id
ORDER BY
    pizza_name, pizzeria_name;