CREATE OR REPLACE FUNCTION fnc_fibonacci(IN pstop INTEGER DEFAULT 10)
RETURNS TABLE(num integer) AS $$
    WITH RECURSIVE cte_fib(num1, num2) AS (
        VALUES (0, 1)
        UNION ALL
            SELECT
                GREATEST(num1, num2), num1 + num2
            FROM cte_fib
            WHERE num2 < pstop
    )
    SELECT num1 FROM cte_fib;
$$ LANGUAGE sql;

SELECT * FROM fnc_fibonacci(100);
SELECT * FROM fnc_fibonacci();

CREATE OR REPLACE FUNCTION fnc_person_visits_and_eats_on_date(
	pperson varchar default 'Dmitriy', 
	pprice numeric default 500,
	pdate date default '2022-01-08')
RETURNS 
TABLE (name varchar) 
AS
$BODY$
BEGIN
RETURN QUERY
SELECT pz.name FROM person_visits AS pv
JOIN person AS p ON p.id = pv.person_id
JOIN menu AS m ON m.pizzeria_id = pv.pizzeria_id
JOIN pizzeria AS pz ON pz.id = m.pizzeria_id
WHERE p.name = pperson AND m.price < pprice AND pv.visit_date = pdate;
END;
$BODY$ 
LANGUAGE PLPGSQL;

select *
from fnc_person_visits_and_eats_on_date(pprice := 800);