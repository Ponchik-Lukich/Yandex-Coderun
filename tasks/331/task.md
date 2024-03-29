# 331. Средняя сетевая задержка

В одном из сервисов организована древовидная структура бэкендов. Запросы в сервис обрабатываются следующим образом: в корневой бэкенд (назовем его balancer.test.yandex.ru) поступает запрос, он формирует подзапросы в бэкенды-потомки (не более одного подзапроса в потомок), ожидает от них ответ, формирует свой ответ и отправляет его пользователю. Каждый из потомков обрабатывает подзапросы по той же схеме. На всех бэкендах регистрируются события следующей структуры:

datetime — время наступления события;

request_id — id запроса;

parent_request_id — id родительского запроса (для корневого бэкенда NULL);

host — имя бэкенда, на котором возникло событие;

type — тип события (список указан ниже);

data — описание события.

События бывают следующих типов:

RequestReceived — на бэкенд поступил новый запрос (поле data пустое);

RequestSent — на бэкенд-потомок был отправлен подзапрос (в поле data записывается имя бэкенда-потомка);

ResponseSent — бэкенд отправил ответ родителю (data пустое);

ResponseReceived — бэкенд получил ответ от потомка (в поле data записываются имя бэкенда-потомка и статус — OK или ERROR — , разделенные символом табуляции).

Все события собираются в одну таблицу. Очевидно, что на каждом бэкенде имеются сетевые издержки на пересылку запросов и ответов. Для одного запроса в корневой бэкенд считаем, что на них тратится сумма разниц datetime между всеми соответствующими парами событий RequestSent/RequestReceived и ResponseSent/ResponseReceived, которые возникли при обработке запроса. Вам нужно посчитать эту величину, усредненную по запросам в корневой бэкенд.

## Формат ввода

Используется БД postgresql 10.6.1 x64.

Система перед проверкой создает таблицу с событиями следующим запросом:

```asm
CREATE TABLE requests (
    datetime TIMESTAMP,
    request_id UUID,
    parent_request_id UUID,
    host TEXT,
    type TEXT,
    data TEXT
);
```

После таблица заполняется тестовыми данными.

## Формат вывода

Напишите SELECT выражение, которое вернет таблицу из одной строки с колонкой avg_network_time_ms типа numeric, в которую будет записана средняя сетевая задержка в миллисекундах.

Внимание! Текст выражения подставится в систему как подзапрос, поэтому завершать выражение точкой с запятой не надо (в противном случае вы получите ошибку Presentation Error).

### Примечание

Для таблицы requests с таким содержимым (здесь для компактности пишем числа вместо UUID'а и миллисекунды в datetime, в проверочной таблице будут UUID'ы и timestamp'ы):
```
datetime	request_id	parent_request_id	host	type	data

.000	0	NULL	balancer.test.yandex.ru	RequestReceived
.100	0	NULL	balancer.test.yandex.ru	RequestSent	backend1.ru
.101	0	NULL	balancer.test.yandex.ru	RequestSent	backend2.ru
.150	1	0	backend1.ru	RequestReceived
.200	2	0	backend2.ru	RequestReceived
.155	1	0	backend1.ru	RequestSent	backend3.ru
.210	2	0	backend2.ru	ResponseSent
.200	3	1	backend3.ru	RequestReceived
.220	3	1	backend3.ru	ResponseSent
.260	1	0	backend1.ru	ResponseReceived	backend3.ru OK
.300	1	0	backend1.ru	ResponseSent
.310	0	NULL	balancer.test.yandex.ru	ResponseReceived	backend1.ru OK
.250	0	NULL	balancer.test.yandex.ru	ResponseReceived	backend2.ru OK
.400	0	NULL	balancer.test.yandex.ru	ResponseSent
.500	4	NULL	balancer.test.yandex.ru	RequestReceived
.505	4	NULL	balancer.test.yandex.ru	RequestSent	backend1.ru
.510	5	4	backend1.ru	RequestReceived
.700	5	4	backend1.ru	ResponseSent
.710	4	NULL	balancer.test.yandex.ru	ResponseReceived	backend1.ru ERROR
.715	4	NULL	balancer.test.yandex.ru	ResponseSent
```
Запрос участника должен возвращать следующий результат:

avg_network_time_ms
149.5

Тут два корневых запроса. Выпишем времена, которые прошли между отправкой запроса/ответа и его получением.

Запрос с id 0

balancer.test.yandex.ru -> backend1.ru — 50 мс (от .100 до .150)

balancer.test.yandex.ru -> backend2.ru — 99 мс (от .101 до .200)

backend1.ru -> backend3.ru — 45 мс (от .155 до .200)

backend2.ru -> balancer.test.yandex.ru — 40 мс (от .210 до .250)

backend3.ru -> backend1.ru — 40 мс (от .220 до .260)

backend1.ru -> balancer.test.yandex.ru — 10 мс (от .300 до .310)

Суммарно это 50+99+45+40+40+10=284 мс

Запрос с id 4

balancer.test.yandex.ru -> backend1.ru — 5 мс (от .505 до .510)

backend1.ru -> balancer.test.yandex.ru — 10 мс (от .700 до .710)

Суммарно это 5+10=15 мс

Итого, ответ (284+15)/2=149.5.