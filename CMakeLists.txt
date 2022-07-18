cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(ip_filter VERSION ${PROJECT_VERSION})

set(INSTALL_GTEST OFF)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/GTEST_LIN" 
"googletest")

add_executable(ip_filter_cli main.cpp)
add_library(lib_IP_filter lib_IP_filt.cpp)
add_executable(test_lib test_IP_filter.cpp)

set_target_properties(ip_filter_cli lib_IP_filter test_lib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(
    test_lib PRIVATE
   ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(ip_filter_cli PRIVATE
    lib_IP_filter
)

target_link_libraries(test_lib PRIVATE
    gtest gtest_main
    lib_IP_filter
)

if (MSVC)

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    target_compile_options(ip_filter_cli PRIVATE
        /W4
    )
    target_compile_options(lib_IP_filter PRIVATE
        /W4
    )
    target_compile_options(test_lib PRIVATE
        /W4
    )
else ()
    target_compile_options(ip_filter_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(lib_IP_filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()



install(TARGETS ip_filter_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(test_lib test_lib)
