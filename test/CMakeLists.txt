set(target ${MP3_TESTS})

file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${target} ${srcs} ${hdrs})
target_link_libraries(${target} gtest ${MP3_LIBRARY})
target_include_directories(${target} PUBLIC ${CMAKE_SOURCE_DIR}/gtest ${MP3_INCLUDE})
add_test(${target} ${target})
