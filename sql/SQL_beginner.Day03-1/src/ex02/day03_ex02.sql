WITH non_menu AS (
    (
    SELECT
        id
    FROM
        menu)
    EXCEPT ALL
    (
        SELECT
            menu_id
        FROM
            person_order
    )
)
SELECT
    mn.pizza_name,
    mn.price,
    piz.name AS pizzeria_name
FROM
    pizzeria piz
    JOIN menu mn ON piz.id = mn.pizzeria_id
WHERE
    mn.id IN (
        SELECT
            id
        FROM
            non_menu
    )
ORDER BY
    pizza_name, price;
