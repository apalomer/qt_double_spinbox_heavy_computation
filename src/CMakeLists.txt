

add_library(qt_double_spinbox_heavy_computation_widget SHARED
    qt_double_spinbox_heavy_computation_widget.cpp
    qt_double_spinbox_heavy_computation_widget.h
    qt_double_spinbox_heavy_computation_widget.ui)
target_compile_definitions(qt_double_spinbox_heavy_computation_widget PRIVATE QTDOULESPINBOXHEAVYCOMPUTATION)
target_link_libraries(qt_double_spinbox_heavy_computation_widget Qt5::Core Qt5::Widgets)

add_executable(qt_double_spinbox_heavy_computation qt_double_spinbox_heavy_computation.cpp)
target_link_libraries(qt_double_spinbox_heavy_computation Qt5::Core qt_double_spinbox_heavy_computation_widget)
