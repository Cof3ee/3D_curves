add_library (3D_curves_library src/Circle.cpp inc/Circle.h src/Ellipse.cpp inc/Ellipse.h src/Helix.cpp inc/Helix.h inc/Curve3D.h inc/Point3D.h inc/Vector3D.h)

target_include_directories(3D_curves_library PUBLIC inc)