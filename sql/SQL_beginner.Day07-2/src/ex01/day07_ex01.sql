SELECT
    p.name, count(p.name) AS count_of_visits
FROM person_visits po
    JOIN person p ON po.person_id = p.id
GROUP BY p.name
ORDER BY
    count_of_visits DESC, p.name
LIMIT 4;