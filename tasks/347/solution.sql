WITH RECURSIVE genre_tree(track_id,	genre_id, track_name, genre_name) AS (
    SELECT track_id, genre_id, track.name, genre.name
    FROM track_genre
             JOIN track ON track.id = track_genre.track_id
             JOIN genre ON genre.id = track_genre.genre_id
    UNION ALL
    SELECT t.track_id, g.parent_genre_id, t.track_name, p.name
    FROM genre_tree t
             JOIN genre g ON g.id = t.genre_id
             JOIN genre p ON p.id = g.parent_genre_id
)
SELECT DISTINCT * FROM genre_tree
ORDER BY track_id, genre_id;