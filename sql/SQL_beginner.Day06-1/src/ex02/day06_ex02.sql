SELECT
    p.name, m.pizza_name, m.price,
    ROUND((1-pd.discount/100)*m.price, 0) AS discount_price,
    pz.name AS pizzeria_name
FROM person_order po
    JOIN menu m ON m.id = po.menu_id
    JOIN pizzeria pz ON m.pizzeria_id = pz.id
    JOIN person p ON po.person_id = p.id
    JOIN person_discounts pd ON p.id = pd.person_id AND pz.id = pd.pizzeria_id
ORDER BY
    name, pizza_name;
