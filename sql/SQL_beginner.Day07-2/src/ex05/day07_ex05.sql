SELECT name
FROM person_order po
JOIN person ON po.person_id = person.id
GROUP BY name
ORDER BY name