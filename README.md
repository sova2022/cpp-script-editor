# Script Editor

Простой редактор Qt Script (.qs) файлов на Qt 5.15 + C++, предназначенный для ручного редактирования скриптов и обмена ими с внешним приложением — Script Runner.

Редактор предоставляет минималистичный UI для просмотра, изменения и сохранения скриптов, а также включает встроенный UDP-сервер, который позволяет приложению-клиенту (например, [Script Runner](https://github.com/sova2022/cpp-script-runner)) удалённо запросить текущий открытый скрипт.

# Зависимости

- **Qt 5.15** (MSVC 2019, 64-bit)  
- **Visual Studio 2019 Build Tools**  
- **CMake >= 3.16**  
- **Git Bash** (для Windows)  
- (Опционально) **Ninja** для быстрой сборки

# Сборка:

```bash
git clone https://github.com/sova2022/cpp-script-editor.git
cd cpp-script-editor
mkdir build && cd build
```

Примечание: если CMake не находит Qt, укажите путь к установке Qt5:
```bash
export CMAKE_PREFIX_PATH="/c/Qt5/5.15.0/msvc2019_64/lib/cmake" # ваш путь к папке msvc2019_64/lib/cmake
```

```bash
cmake -G "Visual Studio 16 2019" -A x64 ..
cmake --build . --config Release # или Debug
```

# Запуск:

Если приложение не запускается из-за отсутствия Qt DLL, добавьте в PATH путь к Qt:
```bash
export PATH="/c/Qt/5.15.0/msvc2019_64/bin:$PATH" # ваш путь к папке msvc2019_64/bin
```

Запуск программы
 ```bash
./Debug/cpp-script-editor.exe   # если собирали Debug
# или
./Release/cpp-script-editor.exe # если собирали Release
 ```




