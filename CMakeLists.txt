cmake_minimum_required(VERSION 3.6)
project(2dTree)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_PREFIX_PATH "/home/ihb/Programs/Qt/5.7/gcc_64/")#указать путь к  Qt
set(CMAKE_AUTOMOC ON)

find_package( Qt5Core REQUIRED )# по аналогии с *.pro QT += gui core
find_package( Qt5Widgets REQUIRED )#виджеты

set(SOURCE_FILES main.cpp workDir/widgets/MainWindow.cpp workDir/widgets/MainWindow.h workDir/widgets/Canvas.cpp workDir/widgets/Canvas.h workDir/utils/Utils.cpp workDir/utils/Utils.h workDir/God.cpp workDir/God.h workDir/algorithm/Tree2D.cpp workDir/algorithm/Tree2D.h)
add_executable(2dTree ${SOURCE_FILES})

target_link_libraries(2dTree Qt5::Widgets Qt5::Core
        ${Boost_LIBRARIES} )# с которыми будем линковать бинарник