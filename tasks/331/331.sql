WITH r1 AS (SELECT (child.datetime - parent.datetime) AS time
FROM requests parent
    JOIN requests child ON parent.request_id = child.parent_request_id
WHERE (parent.type = 'RequestSent' AND child.type = 'RequestReceived' AND
    child.host = parent.data)
   OR (parent.type = 'ResponseReceived' AND child.type = 'ResponseSent' AND
    child.host = (regexp_match(parent.data, '^(.+?)(?:\s+(OK|ERROR))?$'))[1])),
    r2 AS (SELECT COUNT(DISTINCT r.request_id) AS number
FROM requests r
WHERE r.parent_request_id IS NULL
  AND r.type = 'RequestReceived'),
    r3 AS (SELECT SUM(ABS(EXTRACT(epoch FROM r1.time))) * 1000 / r2.number AS avg_network_time_ms
FROM r1
    CROSS JOIN r2
GROUP BY r2.number)
SELECT * FROM r3;