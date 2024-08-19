SELECT
  DISTINCT ps.name
FROM
  person ps
  JOIN person_order as po ON po.person_id = ps.id
  JOIN menu as mn ON mn.id = po.menu_id
WHERE
  mn.pizza_name = 'pepperoni pizza' AND
  ps.name in (
    SELECT
        ps.name
    FROM
        person ps
        JOIN person_order as po ON po.person_id = ps.id
        JOIN menu as mn ON mn.id = po.menu_id
    WHERE
        mn.pizza_name = 'cheese pizza'
  )
  AND ps.gender = 'female'
ORDER BY
  ps.name;