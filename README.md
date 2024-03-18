# OOP
Repository with OOP materials and templates of projects by "Programming Base" (2nd term)

## Ранее выданные работы

**ДЗ0.** Реализация творческой работы "Футбол" с подготовкой презентации и защитой выполненного проекта.

**ПР0**. Решение задач на Stepik на время. 

*Deadline*: на занятии в терминал-классе.

## OOP-Projects

### Project CTime

<details close>

  <summary>Описание ПР1 и ДЗ1 </summary>

  **ПР1**. В соответствии с файлом TC №3 GITHUB (Materials) выложить свой первый код. 
  *Deadline*: **5 марта** в терминал-классе.
  
  **ДЗ1**.
  
  *Шаг 1.* Завершить разработку класса CTime (Время).
  
  *Шаг 2.* Создать pull request и получить ревью от двух одногруппников - запросить после этого ревью от меня (@UsovaMA).
  
  *Шаг 3.* По аналогии создать и разработать класс CDate (Дата) в другой ветке разработки (создавать новую ветку следует находясь в главной ветке!).
  
  *Шаг 4.* Создать еще один pull request и получить ревью от двух одногруппников - запросить после этого ревью от меня (@UsovaMA).
  
  *Требования:*
  * код должен быть реализован на С++ с соблюдением концепций ООП,
  * в процессе работы качественно вести историю в коммитах.
  *Deadline*: 1 неделя (до **12 марта**).

</details>  

### Project CString

<details close>

  <summary>Описание ПР2 </summary>

  **ПР2**. Реализовать класс Строка, используя выложенный шаблон
  * [string.h](https://github.com/UsovaMA/OOP/blob/main/OOP-Projects/CString/string.h)
  * [string.cpp](https://github.com/UsovaMA/OOP/blob/main/OOP-Projects/CString/string.cpp)
  * [main.cpp](https://github.com/UsovaMA/OOP/blob/main/OOP-Projects/CString/main.cpp)
  
  *Как работать с задачей:*
  * создать очередную рабочую ветку (находясь в ветке main),
  * скачать файлы-заготовки по ссылкам, создать проект с ними (создать проект, перейти в папку проекта - там будут 3 конфигурационных файла - положить там скаченные файлы, подхватить их в MVS: ПКМ по проекту - Добавить - Существующий элемент),
  * запустить, разобраться с тем, что в проекту уже реализовано.
  
  Далее:
  * раскомментировать очередную функцию из объявления класса в файле string.h,
  * реализовать её в файле string.cpp,
  * написать пару строк кода проверки её работы в файле main.cpp,
  * оформить комментарий к реализованной функции.
  
  *Требования к реализации:*
  * осуществить корректное выставление спецификаторов const (функция не меняет объект this), noexcept (в функции нет исключений) для методов,
  * в процессе реализации оформлять корректно "документацию кода",
  * создавать историю коммитов для github (например, добавлена рализация всех конструкторов, реализованы все варианты функций вставки, ... функций поиска и т.д.),
  * весь написанный функционал должен быть исчерпывающе проверен в функции main(),
  * в конце терминал-класса сделать push всего реализованного за занятие в репозиторий. 
  
  *Deadline*: **12 марта** в терминал-классе начать работу, завершить разработку за 1 неделю (до **19 марта**).

</details> 

### Project CArchive

<details close>
  <summary>Описание ДЗ2 </summary>
  
  **ДЗ2**. Реализовать переосмысление работы «Архив» из 1-го семестра. Использовать шаблон
  * [archive.h](https://github.com/UsovaMA/OOP/blob/main/OOP-Projects/TArchive/archive.h)
  * [utilities.h](https://github.com/UsovaMA/OOP/blob/main/OOP-Projects/TArchive/utilities.h)
  * [main.cpp](https://github.com/UsovaMA/OOP/blob/main/OOP-Projects/TArchive/main.cpp)
  
  *Как работать с задачей:*
  * создать очередную рабочую ветку (находясь в ветке main),
  * скачать файлы-заготовки по ссылкам,
  * собрать проект с файлами шаблона,
  * запустить и посмотреть как он работает (в текущем шаблоне реализована только вставка (п.1) на заданную позицию (п.3) одного элемента (п.1) в качестве примера как грамотно разделять обязанности между функциями и вызывать их в меню с отловом исключений),
  * разобраться как работают те элементы, которые уже написаны в качестве примера.
  
  Далее:
  * раскомментировать очередную функцию из объявления класса в файле archive.h,
  * реализовать её в этом же файле (обратите внимание, объявление и реализация **шаблонных** классов и функций **должны быть в одном файле**!),
  * если это один из основных алгоритмов (вставка, поиск, удаление, замена) или другое действие существующее в меню (например, очистка архива) - найти её место в меню в файле main.cpp, реализовать для её работы отдельно в InputSystem и OutputSystem общение с пользователем для ввода значений для этих алгоритмов или вывода результатов,
  * проверить работоспособность  после добавления очередного пункта меню.
  
  *Требования к реализации:*
  * код должен быть реализован на С++ с соблюдением концепций ООП,
  * осуществлять качественное разделение кода на функции:
  1. одна функция - одно действие,
  2. функции интерфейса (ввода/вывода информации в нужном формате) должны быть реализованы отдельно аналогично примеру с insert в именном пространстве InputSystem/OutputSystem, **в функциях класса-архива НЕ может быть общения с пользователем и вывода сообщений на экран** - это обязанности интерфейса (исключение: функция print(), которая выводит содежимое хранилища на экран),
  * осуществить корректное выставление спецификаторов const (функция не меняет объект this), noexcept (в функции нет исключений), static (функция становится явно статической - https://www.geeksforgeeks.org/what-are-static-functions-in-c/), inline (при компиляции код этой функции будет вставляться на месте вызовов),
  * должно быть продемонстрировано использование перечислений, именных пространств и шаблонных функций в соответствии с примером,
  * должно быть продемонстрировано корректное использование указателей и ссылок (старайтесь повсеместно переходить на использование ссылок, если это коненчно не массив, который передаётся традиционно по указателю),
  * должна быть использована механика исключений (throw) и их обработки (try .. catch), исключения должны быть написаны как минимум везде, где возможны некорректные входные данные,
  * оформить документацию кода,
  * создать качественную историю коммитов для github,
  * реализовать полноценное приложение в main().
  
  *Требования к выводу в меню:*
  1. Меню должно быть понятным и качественно оформленным.
  2. После выполнения любого поиска выводить информацию в понятном виде (функция должна быть реализована в именном пространстве OutputSystem):
  ```
  Matches found: 3, 5, 6, 7, 13
  42441, 112, 24, 333, 426, 333, 333, 333, 335, 426, 42427,
                  ^         ^    ^    ^               
  24, 335, 333, 42427
           ^
  ```        
  Даже если это поиск одного элемента, его также нужно выделить в потоке информации. Советую создать вспомогательную функцию, подсчитывающую количество цифр в числе, а также поиспользовать уже написанные, getCursor, setCursor.
  
  *Прочее:*
  
  Допускается добавление нового (не продуманного в шаблоне) служебного функционала.
  
  *Deadline*: 2 недели (до **26 марта**).

 </details>
   
 #### Тонкости реализации и описание алгоритмов
    
 <details close>
  <summary>Представление в памяти и создание архива по умолчанию</summary>
    
 По умолчанию под архив выделается некоторое фиксированное количество ячеек памяти и считается, что в архиве нет элементов {  } (т.е. состояние всех ячеек empty)
    
  _capacity = 15; _size = 0; _deleted = 0;
  
  _data:
  
  ![image](https://github.com/UsovaMA/OOP/assets/22386453/1fcfeb52-b5ab-4d43-9cc8-a685533201a8)
  
  _states:
  
  ![image](https://github.com/UsovaMA/OOP/assets/22386453/26a908aa-df0e-442e-aa6e-f1f8fddea9da)
  </details>
  
  <details close>
    <summary>Вставка</summary>
      
    При **вставке** элемента он занимает некоторую ячейку состояние ячейки помечается как busy. Например, после вставки в конец элементов 12, 34, 56:
    
    _capacity = 15; _size = 3; _deleted = 0;
    
    _data:
    
    ![image](https://github.com/UsovaMA/OOP/assets/22386453/545eb590-9e9b-46b7-96f6-72075bdfcbd8)
    
    _states:
    
    ![image](https://github.com/UsovaMA/OOP/assets/22386453/7d08dd99-0b22-4898-baec-4956a1a6725b)
      
  </details> 
    
  <details close>
    <summary>Удаление</summary>
    
    При **удалении** элемента из конца _size уменьшается на 1, а статус меняется на empty, во всех остальных случаях удаления статус элемента меняется на deleted и больше ничего не совершается. Например, пусть был архив { 12, 34, 56, 647, 89, 985 }. Удалили элементы с индексом  2 (значение 56) и 5 (значение 985). В результате на экране должно быть { 12, 34, 647, 89 }, но фактически в переменных происходит следующее:
    
    _capacity = 15; _size = 5; _deleted = 1;
    
    _data:  
    
    ![image](https://github.com/UsovaMA/OOP/assets/22386453/92a93acf-ae84-4e3a-90e3-34c6a3f801cb)
    
    _states:
    
    ![image](https://github.com/UsovaMA/OOP/assets/22386453/155ccdb0-0a58-4fb9-92c1-616f37d486ad)
    
    то есть так как элемент 985 был последним его ячейка пометилась как свободная и размер архива уменьшился, в то время как значение 56 просто пометилось удалённым и будет пропускаться при выводе на экран архива.
    
  </details> 
    
  <details close>
    <summary>Перепаковка (перераспределние памяти)</summary>
  
    1. Не хватает памяти для вставки.
    
    Если при попытке добавить элемент архив заполнен (метод full() вернул true, т.е. _capacity == _size):
    
    * архив перестраивается с учетом удалённых элементов
    
    **ДО**
    
    _data: 
    
    ![image](https://github.com/UsovaMA/OOP/assets/22386453/15bf63a5-4000-407a-a56a-54ab6bef676f)
    
    _states:
    
    ![image](https://github.com/UsovaMA/OOP/assets/22386453/f25f7a73-be8d-4f64-a382-0b88a3c542dd)
    
    **ПОСЛЕ**
    
    _data: 
    
    ![image](https://github.com/UsovaMA/OOP/assets/22386453/fb4fde17-468b-4eb7-ad80-a3b400f94c4a)
    
    _states:
    
    ![image](https://github.com/UsovaMA/OOP/assets/22386453/cf7274cc-d19d-4997-8c8e-9fab424c0eca)
    
    * если удалённых элементов нет, то происходит расширение памяти
    
    **ДО**
    
    _data: 
    
    ![image](https://github.com/UsovaMA/OOP/assets/22386453/3decc156-5407-46b9-80d2-4a8bad9dd9f1)
    
    _states:
    
    ![image](https://github.com/UsovaMA/OOP/assets/22386453/08ffde80-97aa-4618-953b-05d2be254b0d)
    
    **ПОСЛЕ**
    
    _data: 
    
    ![image](https://github.com/UsovaMA/OOP/assets/22386453/6be4b32d-5c08-416b-a765-be6a68c393cb)
    
    _states:
    
    ![image](https://github.com/UsovaMA/OOP/assets/22386453/2db2302d-ac9f-4c01-bebd-68f8da2112b7)
    
    2. Если количество удалённых элементов после очередного удаления становится, например, 40% от _size, то следует перестроить массив аналогично первому случаю исключив удаленные элементы.
  </details> 
</details> 

### Project CFraction

<details close>

  <summary>Описание ПР3</summary>

  **ПР3**. Реализовать класс Дробь.

  ```
  class Fraction {
      int numerator;       // числитель
      int denominator;     // заменатель
   public:
      ...
  };
  ```
 *Требования к реализации:*
  * поля класса:
    + числитель,
    + заменатель;
  * обязательные методы класса:
    + 4 основных конструктора (по умолчанию, инициализации, копирования, преобразования из вашей строки, т.е. CString), деструктор (при необходимости),
    + **внутренняя** перегрузка оператора присваивания = (обязательно с проверкой на самоприсваивание),
    + перегрузка операторов сравнения ==, !=, >, <, >=, <= с целочисленным значением (int),
    + перегрузка операторов сравнения ==, !=, >, <, >=, <= с другой дробью (СFraction),
    + перегрузка арифметических операторов +, -, +=, *, /, -=, *=, /= с целочисленным значением (int),
    + перегрузка арифметических операторов +, -, +=, *, /, -=, *=, /= с другой дробью (СFraction),
    + **внешняя** перегрузка операторов ввода >> и вывода <<,
    + метод `void simplify();` максимально сокращающий дробь;

P.S.: если не сказано, какой тип перегрузки нужен, следует определиться с ним самостоятельно, однако обратите внимание, что при перегрузке операторов, работающих с другим типом требуется две перегрузки (когда int справа от оператора и когда int слева от оператора), которые можно реализовать как раз как внешние:
```
friend Fraction operator+(const Fraction& frac, int value);
friend Fraction operator+(int value, const Fraction& frac);
```
Тогда как при перегрузке внутренним способом int сможет стоять только справа от операции.
  * осуществить корректное выставление спецификаторов const (функция не меняет объект this), noexcept (в функции нет исключений) для методов,
  * в процессе реализации оформлять корректно "документацию кода",
  * создавать историю коммитов для github (например, добавлена рализация всех конструкторов, реализованы все варианты функций вставки, ... функций поиска и т.д.),
  * весь написанный функционал должен быть исчерпывающе проверен в функции main(),
  * в конце терминал-класса сделать push всего реализованного за занятие в репозиторий. 
  
  *Deadline*: **19 марта** в терминал-классе начать работу, завершить разработку за 1 неделю (до **26 марта**).

</details> 
