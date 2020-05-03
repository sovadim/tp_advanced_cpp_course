# Homework 2

## Task

Создать библиотеку с именем log. Функционал библиотеки должен позволять записывать лог программы в стандартные потоки ввода/вывода и в файл.</br>
Лог должен обладать 4 уровнями: **debug**, **info**, **warning**, **error**.

Библиотека должна гарантировать базовую безопасность исключений и соответствовать диаграмме классов

## Class diagram

![Class diagram](./images/pic1.png)

![Class diagram 2](./images/pic2.png)

## Implementation progress

- [ ] Logger
- [ ] BaseLogger
- [ ] FileLogger
- [ ] StdoutLogger
- [ ] StderrLogger
- [ ] Exceptions

## How to build

Build log library

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
```

To build library and samples you can run script used in ci

```bash
$ cd ..
$ ./ci/hw2/build.sh
```