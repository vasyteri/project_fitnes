cmake_minimum_required(VERSION 3.16)
project(CalorieCalculator LANGUAGES CXX)

# Настройка Qt6
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)    # Для автоматической обработки Q_OBJECT
set(CMAKE_AUTORCC ON)    # Для ресурсов Qt
set(CMAKE_AUTOUIC ON)    # Для UI-форм

# Поиск необходимых Qt-модулей
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Добавление исходных файлов
set(SOURCES
    main.cpp
    mainwindow.cpp
    product.cpp
    user.cpp
    productdatabase.cpp
    shoppingcart.cpp
)

set(HEADERS
    mainwindow.h
    product.h
    user.h
    productdatabase.h
    shoppingcart.h
)

# Добавление UI-формы
qt6_wrap_ui(FORMS_HEADERS MainWindow.ui)

# Создание исполняемого файла
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${FORMS_HEADERS})

# Подключение Qt-модулей
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)

# Копирование файла с продуктами
configure_file(products.txt ${CMAKE_CURRENT_BINARY_DIR}/products.txt COPYONLY)
