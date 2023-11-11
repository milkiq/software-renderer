# FILEPATH: /d:/project/software-renderer/wmath/CMakeLists.txt

file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(wmath STATIC ${SRCS})
target_include_directories(wmath PUBLIC include)
