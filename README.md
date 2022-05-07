# TP Project

### Как запустить проект на linux

Установить библиотеку SFML и cmake:

```bash
sudo apt-get install libsfml-dev
sudo apt install cmake
```
В папке tp-project:

```bash
./run.sh   
```

## Используемые паттерны

1. **MVC** - мы разделили логику персонажа на три части согласно концепции MVC (когда начали писать код, возникли трудности связанные с архитектурой, взаимосвязями модулей; MVC показалось хорошим решением): класс **Model** - внутренняя логика (в основном физика), **View** - то, что относится к рисованию и анимации, **Control** - контроль персонажа со стороны пользователя. У View и Control должен быть доступ к Model (View - чтобы брать информацию из Model, Control - чтобы изменять её), поэтому в них храним указатели на соответствующий объект Model.
2. **Адаптер**. Для удобного построения карты мы используем файлы, в которых закодирована информация о них. В файле находится таблица из символов; каждый символ кодирует некоторый тайл (кусок карты). Чтобы брать информацию из файла, был написан класс **ConverterFromFileToMap** - по факту реализован паттерн адаптер.
3. На карте находится много одинаковых тайлов. Создавать под каждый отдельный тайл объект класса **MainTile** было бы расточительным, поэтому, чтобы избежать копирования одинаковых текстур, реализованы четыре тайла, которые отличаются свойствами: **Air**, **DefaultTile**, **DamageTile** и **StoneTile**. В остальном коде мы работаем с ними через указатели - **Singleton**.

