cmake_minimum_required(VERSION 3.10)
project(SFRR VERSION 0.1.0 LANGUAGES C CXX)

# set(Eigen3_DIR "D:/software/CPPLib/eigen/share/eigen3/cmake")
# find_package(Eigen3 REQUIRED)
# include_directories(${EIGEN3_INCLUDE_DIR})

set(EGE_INC_DIR "D:/software/CPPLib/EGE20.08/include")
set(EGE_LINK_DIR "D:/software/CPPLib/EGE20.08/lib/mingw64")

include_directories(${EGE_INC_DIR})
link_directories(${EGE_LINK_DIR})

add_executable(SFRR main.cpp)

# target_link_libraries(SFRR graphics.lib)
target_link_libraries(SFRR 
    libgraphics64.a
    libgdi32.a
    libimm32.a
    libmsimg32.a
    libole32.a
    liboleaut32.a
    libwinmm.a
    libuuid.a
    libgdiplus.a)