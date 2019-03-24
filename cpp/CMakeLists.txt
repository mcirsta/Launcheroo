set("${CMAKE_PROJECT_NAME}_SOURCES"
       main.cpp
       platform.cpp
       iconprovider.cpp
)

set("${CMAKE_PROJECT_NAME}_HEADERS"
       platform.hpp
       iconprovider.hpp
)

find_package(Qt5XdgIconLoader ${QTXDG_MINIMUM_VERSION} REQUIRED)


include_directories(${Qt5Widgets_INCLUDE_DIRS} ${Qt5Qml_INCLUDE_DIRS} ${Qt5Quick_INCLUDE_DIRS} ${Qt5Gui_PRIVATE_INCLUDE_DIRS})


find_package(Qt5QuickCompiler REQUIRED)

qtquick_compiler_add_resources(RESOURCES ${PROJECT_SOURCE_DIR}/qml/qml.qrc)


add_executable(${CMAKE_PROJECT_NAME} ${launcheroo_SOURCES} ${${CMAKE_PROJECT_NAME}_HEADERS} ${RESOURCES})
target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Core Qt5::Quick Qt5XdgIconLoader)
