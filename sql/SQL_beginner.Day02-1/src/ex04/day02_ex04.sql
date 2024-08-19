SELECT
    menu.pizza_name,
    piz.name AS pizzeria_name,
    menu.price
FROM
    menu
    JOIN pizzeria piz on piz.id = menu.pizzeria_id
WHERE
    pizza_name IN (
        'pepperoni pizza', 'mushroom pizza'
    )
ORDER BY
    pizza_name, pizzeria_name;