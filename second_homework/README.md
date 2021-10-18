# Второе домашнее задание

Чтобы сделать бинарь, нужно зайти в папку ```cmake-build-debug``` и прописать ```make```.

Соберется бинарь ```second_homework```, использовать его нужно следующим образом:

```../cmake-build-debug $ ./second_homework <input file> <output file>```

---
Если данные из файла считываются, то входной файл выглядит так:

```m <number of shapes>```
```<shape type> [params]```

Если данные генерятся рандомно, то входной файл выглядит так:

```r <number of shapes>```

---
```0 <radius> <density>``` - это сфера

```1 <width> <length> <height> <density>``` - это параллелепипед

```2 <side> <density>``` - это тетраэдр
