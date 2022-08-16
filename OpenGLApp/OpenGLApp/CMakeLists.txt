cmake_minimum_required (VERSION 3.8)

set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_SOURCE_DIR}/OpenGLApp/rc/appicon.rc")
set(UTILS "include/Utils.cpp" "include/Utils.h")
set(HELLOWORLD "include/Tutorials/HelloWorld/HelloWorld.cpp" "include/Tutorials/HelloWorld/HelloWorld.h")
set(MENUCALLBACK "include/Tutorials/MenuCallback/MenuCallback.cpp" "include/Tutorials/MenuCallback/MenuCallback.h")

find_package(OpenGL REQUIRED)
link_directories(${CMAKE_SOURCE_DIR}/OpenGLApp/lib)


add_executable (HelloWorld ${HELLOWORLD} "include/Main.cpp" ${UTILS} ${APP_ICON_RESOURCE_WINDOWS})
target_link_libraries(HelloWorld OpenGL::GL)
include_directories(HelloWorld "./include/gl")
include_directories(HelloWorld "./include")
target_compile_definitions(HelloWorld PUBLIC HELLOWORLD)

add_executable (MenuCallback ${MENUCALLBACK} "include/Main.cpp" ${UTILS} ${APP_ICON_RESOURCE_WINDOWS})
target_link_libraries(MenuCallback OpenGL::GL)
include_directories(MenuCallback "./include/gl")
include_directories(MenuCallback "./include")
target_compile_definitions(MenuCallback PUBLIC MENUCALLBACK)


add_custom_command(TARGET HelloWorld POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
      ${CMAKE_SOURCE_DIR}/OpenGLApp/bin
      ${CMAKE_BINARY_DIR}/OpenGLApp)