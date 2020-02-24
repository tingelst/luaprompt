cmake_minimum_required(VERSION 3.5)
project(luaprompt)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall
                      -Wextra
                      -Wno-unused-parameter
                      -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(Lua 5.3 REQUIRED)

add_library(prompt SHARED src/prompt.c src/module.c)
target_include_directories(
  prompt
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include> ${LUA_INCLUDE_DIR})
target_link_libraries(prompt
                      -lreadline
                      -lhistory
                      ${LUA_LIBRARIES})
target_compile_definitions(prompt
                           PRIVATE
                           -DHAVE_ASPRINTF
                           -DHAVE_LIBREADLINE
                           -DHAVE_READLINE_HISTORY
                           -D_GNU_SOURCE
                           -DCOMPLETE_KEYWORDS
                           -DCOMPLETE_MODULES
                           -DCOMPLETE_TABLE_KEYS
                           -DCOMPLETE_METATABLE_KEYS
                           -DCOMPLETE_FILE_NAMES
                           -DSAVE_RESULTS
                           -DRESULTS_TABLE_NAME="_"
                           # -DWEAK_RESULTS
                           # -DHIDDEN_KEY_PREFIX="_"
                           # -DALWAYS_APPEND_SUFFIXES
                           # -DNO_MODULE_LOAD
                           # -DCONFIRM_MODULE_LOAD
                           )

# Causes the visibility macros to use dllexport rather than dllimport, which is
# appropriate when building the dll but not consuming it.
target_compile_definitions(prompt PRIVATE "LUAPROMPT_BUILDING_LIBRARY")

ament_environment_hooks(env_hook/luaprompt.sh.in)

install(DIRECTORY include/ DESTINATION include)
install(TARGETS prompt
        EXPORT export_${PROJECT_NAME}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights uncomment
  # the line when a copyright and license is not present in all source files
  # set(ament_cmake_copyright_FOUND TRUE) the following line skips cpplint (only
  # works in a git repo) uncomment the line when this package is not in a git
  # repo set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_export_include_directories(include)
ament_export_interfaces(export_${PROJECT_NAME})
ament_export_libraries(prompt)

ament_package()
