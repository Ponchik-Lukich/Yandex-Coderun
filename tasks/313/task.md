# 313. Сумма медиан

Коля очень любит занятия по программированию в университете. А еще больше он любит узнавать новые алгоритмы и структуры данных. Для того, чтобы ему не было скучно на очередном занятии, преподаватель предложил придумать способ поиска медианы для последовательности X из n элементов.

Коля быстро нашел в сети нужный алгоритм и отчитался перед учителем. Тогда тот предложил усложнённую версию задачи: для каждого i от 1 до n нужно найти медиану среди первых i элементов последовательности X. В качестве результата преподаватель попросил сказать сумму найденных значений.

Медианой последовательности в случае нечётной длины L называется элемент, который будет равноудалён от концов последовательности, если ее отсортировать по возрастанию или убыванию (нетрудно сообразить, что этот элемент имеет номер (L+1)/2 в отсортированной последовательности, если номера считать с единицы). В случае чётной длины L медианой будем считать элемент, который окажется на месте L/2, если последовательность отсортировать по возрастанию.

## Формат ввода

В первой строке входных данных записано число N (1≤N≤100000). Во второй строке записаны N различных целых чисел Xi (1≤Xi≤10^9).

## Формат вывода

Выведите сумму найденных медианных значений.

### Пример 1

**Ввод:**
```
10
5 10 8 1 7 3 9 6 2 4
```

**Вывод:**
```
59
```

### Пример 2

**Ввод:**
```
5
5 3 1 2 4
```

**Вывод:**
```
16
```