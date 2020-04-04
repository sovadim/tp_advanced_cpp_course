# Homework 1

## Task

Нужно реализовать класс Process, согласно интерфейсу.
Класс представляет собой процесс операционной системы
Linux.

При создании экземпляра класса создается дочерний
процесс, при уничтожении переменной все ресурсы
освобождаются, процесс завершается.

Класс позволяет отправлять данные на стандартный поток
ввода процесса и читать данные с его стандартного
потока вывода.

Все исключительные ситуации должны быть корректно
описаны и передавать управление вызывающему коду

## Process inteface

```cpp
#ifndef PROCESS_H
#define PROCESS_H

class Process
{
public:
    explicit Process(const std::string& path);
    ~Process();

    size_t write(const void* data, size_t len);
    void writeExact(const void* data, size_t len);
    size_t read(void* data, size_t len);
    void readExact(void* data, size_t len);

    bool isReadable() const;
    void closeStdin();

    void close();
};

#endif //PROCESS_H
```

## Implementation progress

- [x] explicit Process(const std::string& path);
- [x] ~Process();
- [x] size_t write(const void* data, size_t len);
- [x] void writeExact(const void* data, size_t len);
- [x] size_t read(void* data, size_t len);
- [x] void readExact(void* data, size_t len);
- [x] bool isReadable() const;
- [x] void closeStdin();
- [x] void close();

## How to build

```bash
$ cd processlib
$ mkdir build
$ cd build
$ cmake ..
$ make
```
