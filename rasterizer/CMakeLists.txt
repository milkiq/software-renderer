# FILEPATH: /d:/project/software-renderer/rasterizer/CMakeLists.txt
file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(rasterizer STATIC ${SRCS})
target_include_directories(rasterizer PUBLIC include)
target_link_libraries(rasterizer PUBLIC wmath)
