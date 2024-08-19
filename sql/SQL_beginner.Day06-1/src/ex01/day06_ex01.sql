WITH aggr_pizzeria_id AS (
    SELECT
        menu.id AS menu_id, pizzeria_id
    FROM menu
        JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
    GROUP BY
        pizzeria_id, menu_id
)

INSERT INTO person_discounts(id, person_id, pizzeria_id, discount)(
SELECT ROW_NUMBER() OVER() AS
    id, person_id, pizzeria_id,
    (
       CASE
        WHEN
            COUNT(po.person_id) = 1 THEN 10.5
        WHEN
            COUNT(po.person_id) = 2 THEN 22
        ELSE
           30
        END
    )
FROM person_order po
    JOIN aggr_pizzeria_id ON po.menu_id = aggr_pizzeria_id.menu_id
    GROUP BY po.person_id, aggr_pizzeria_id.pizzeria_id
ORDER BY
    person_id
);