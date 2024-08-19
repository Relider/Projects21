CREATE VIEW v_price_with_discount AS(
    SELECT
        ps.name,
        mn.pizza_name,
        mn.price,
        ROUND(mn.price-0.1*mn.price, 0) AS discount_price
    FROM person_order po
        JOIN person ps ON po.person_id = ps.id
        JOIN menu mn ON po.menu_id = mn.id
    ORDER BY
        ps.name, mn.pizza_name
);
SELECT
    *
FROM
    v_price_with_discount;