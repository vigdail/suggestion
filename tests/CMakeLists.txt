set(CXX_STANDARD 20)

add_executable(distance distance.cpp)

target_include_directories(distance PRIVATE ../)
target_link_libraries(distance Levenshtein)
set_property(TARGET distance PROPERTY CXX_STANDARD 20)

add_executable(suggest suggest.cpp)

target_include_directories(suggest PRIVATE ../)
target_link_libraries(suggest Levenshtein)
set_property(TARGET suggest PROPERTY CXX_STANDARD 20)

add_test(NAME "distance_1" COMMAND "distance" "aaa" "aaa" 0 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
add_test(NAME "distance_2" COMMAND "distance" "aaa" "" 3 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
add_test(NAME "distance_3" COMMAND "distance" "" "aa" 2 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
add_test(NAME "distance_4" COMMAND "distance" "a" "aa" 1 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
add_test(NAME "distance_5" COMMAND "distance" "ab" "aa" 1 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
add_test(NAME "distance_6" COMMAND "distance" "kitten" "sitting" 3 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
add_test(NAME "distance_7" COMMAND "distance" "hello" "pie" 5 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME "suggest_1" COMMAND "suggest" "hello" "pie circle hello wolf" "hello")
add_test(NAME "suggest_2" COMMAND "suggest" "hell" "pie circle hello wolf" "hello")
add_test(NAME "suggest_3" COMMAND "suggest" "golf" "pie circle hello wolf" "wolf")
add_test(NAME "suggest_4" COMMAND "suggest" "" "pie circle hello wolf" "pie")
add_test(NAME "suggest_5" COMMAND "suggest" "hello" "wolf" "wolf")