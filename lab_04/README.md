# Лабораторная работа № 4

## Сборка

Для запуска необходимо установить

* qt libraries
* cmake
* make
* g++

Пример запуска на ubuntu

```sh
sudo apt install qt5-default cmake make g++
mkdir cmake-build
cd cmake-build
cmake ../
make
./lab_04
```

## Задание

Реализовать поведения лифта при его вызове на тех или иных этажах
с использоваем состояний (управляющая панель, кабина, двери или как-то иначе).

## Замечания к работе

Лифт находился на 5ом этаже. Его вызвали на 2ом. Пока лифт спускался - его так
же вызвали на 3ем. Однако в текущей реализации лифт не остановится на 3ем.
Хотя обычно так лифты останавливаются. Было бы здорово исправить это.

---

Автор: [maxerMU](https://github.com/maxerMU)
