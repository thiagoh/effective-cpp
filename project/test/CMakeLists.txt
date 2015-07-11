enable_testing()
#add_definitions (-DBOOST_TEST_DYN_LINK)

find_package(Boost REQUIRED COMPONENTS thread system unit_test_framework REQUIRED)

include_directories(
    ${Boost_INCLUDE_DIRS} 
    ${CMAKE_SOURCE_DIR} 
	${CMAKE_SOURCE_DIR}/src/include)
	
message("Boost include dir: ${Boost_INCLUDE_DIRS}")
message("Boost libraries: ${Boost_LIBRARIES}")
	
add_executable (test tests_1.cpp)

target_link_libraries(test 
	app_project
	${Boost_LIBRARIES} 
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
	
add_test(TestCase1 test)
