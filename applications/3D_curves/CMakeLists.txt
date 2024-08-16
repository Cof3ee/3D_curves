add_executable(3D_curves main.cpp)

target_link_libraries(3D_curves PUBLIC 3D_curves_library)

target_include_directories(3D_curves PUBLIC ../../libraries/3D_curves_library/inc)