select
    dt::date as missing_date
from
    generate_series(
        '2022-01-01', '2022-01-10', interval '1 day'
    ) as dt
    LEFT JOIN (
        SELECT
        *
        FROM
        person_visits
        WHERE
        person_id = 1
        OR person_id = 2
    ) as v on dt = v.visit_date
WHERE
  person_id IS NULL
ORDER BY
  dt;