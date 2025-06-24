"# Student_Manager" 
# 🎓 Student Manager

🗂️ **Student Manager** — это консольное C++ приложение для управления студентами и оценками.  
Позволяет удобно работать с данными: загружать студентов из файла, добавлять оценки по предметам, вести электронный дневник.

---
✍️Основная суть проекта, просто практика!😁
---
## 🚀 Возможности

- ✅ Загрузка студентов из файла (`students.txt`)
- ✅ Поиск студента по имени
- ✅ Назначение оценки по выбранному предмету
- ✅ Запись оценок в журнал (`book.txt`)
- ✅ Список уроков
- ✅ Простая архитектура

---

## 🏗️ Структура проекта

📁 Student_Manager/
├── 📂 include/ # Заголовки: Student.h, Lessons.h
├── 📂 src/ # Логика: Student.cpp, Lessons.cpp
├── 📄 main.cpp # Точка входа
├── 📄 students.txt # Пример студентов (имя + балл)
├── 📄 lessons.txt # Предметы
├── 📄 book.txt # Файл-табель
└── 📄 README.md # Документация


---

## 📚 Формат входных файлов

**students.txt**

Ivan 4.5
Anna 5
Dima 3.8


**lessons.txt**

Math
History
Physics
Literature
Geometry
Informatics
Chemistry


---

## ⚙️ Сборка и запуск

### 🧰 Требования:
- C++17 или выше
- g++ / clang / MSVC
- (по желанию) CMake

### 🔧 g++:
```bash
g++ -std=c++17 -Wall -Iinclude src/*.cpp main.cpp -o student_manager
./student_manager

🧱 CMake:

mkdir build && cd build
cmake ..
make
./student_manager

🖥 Пример работы

Введите имя студента: Ivan
Введите имя файла студентов: students.txt
Введите предмет: Math
Введите оценку: 5

📄 Результат (book.txt):

Ivan Math 5.0



---

👤 Автор

    GitHub: Gerakl1123 aka German Niyazyan

    ⭐️ Поставь звёздочку, если проект был полезен или вдохновил тебя!


---
в обновление 20.06.2025
добавлено
новый класс Lesson
- исправление недочетов и 1 бага изменена структура методов убрал cin в методах
- рефакторинг чуть 
Скоро... в обновление 24-25.06.2025
добавленик нового класса Contest + рефоакторинг 
Написание Тестов на GTEST

