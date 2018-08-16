cmake_minimum_required(VERSION 3.2)
project(new_pyigl)
set(CMAKE_CXX_STANDARD 14)

# NumpyEigen
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/../external/numpyeigen/cmake)
include(numpyeigen)


# LibIGL
option(LIBIGL_USE_STATIC_LIBRARY "Use libigl as static library" OFF)
option(LIBIGL_WITH_ANTTWEAKBAR      "Use AntTweakBar"    OFF)
option(LIBIGL_WITH_CGAL             "Use CGAL"           OFF)
option(LIBIGL_WITH_COMISO           "Use CoMiso"         OFF)
option(LIBIGL_WITH_CORK             "Use Cork"           OFF)
option(LIBIGL_WITH_EMBREE           "Use Embree"         OFF)
option(LIBIGL_WITH_LIM              "Use LIM"            OFF)
option(LIBIGL_WITH_MATLAB           "Use Matlab"         OFF)
option(LIBIGL_WITH_MOSEK            "Use MOSEK"          OFF)
option(LIBIGL_WITH_NANOGUI          "Use Nanogui menu"   OFF)
option(LIBIGL_WITH_OPENGL           "Use OpenGL"         OFF)
option(LIBIGL_WITH_OPENGL_GLFW      "Use GLFW"           OFF)
option(LIBIGL_WITH_PNG              "Use PNG"            OFF)
option(LIBIGL_WITH_PYTHON           "Use Python"         OFF)
option(LIBIGL_WITH_TETGEN           "Use Tetgen"         OFF)
option(LIBIGL_WITH_TRIANGLE         "Use Triangle"       OFF)
option(LIBIGL_WITH_VIEWER           "Use OpenGL viewer"  OFF)
option(LIBIGL_WITH_XML              "Use XML"            OFF)

if(NOT TARGET igl::core)
  list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/../shared/cmake")
  include(libigl)
endif()


# A module for writing bindings with our framework
file(GLOB PYIGL_SOURCES src/*.cpp)
npe_add_module(pyigl
  BINDING_SOURCES
  ${PYIGL_SOURCES})
target_link_libraries(pyigl PRIVATE igl::core)
target_include_directories(pyigl PRIVATE ${PYBIND_11_DIR}/include)


#set(Python_ADDITIONAL_VERSIONS 3.4 3.5 3.6)
#find_package(PythonLibs REQUIRED)
#find_package(PythonInterp REQUIRED)
#target_link_libraries(pyigl PRIVATE ${PYTHON_LIBRARIES})
#set_target_properties(pyigl PROPERTIES LINK_FLAGS "-Wl,--no-undefined")
#set_target_properties(pyigl PROPERTIES COMPILE_FLAGS "-Os -fvisibility=hidden")
