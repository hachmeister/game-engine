cmake_minimum_required(VERSION 2.6)

# Project name.
project(ENGINE)

# Set version number
set (MY_VERSION_MAJOR 0)
set (MY_VERSION_MINOR 0)

# Set default build type.
if (CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "[Debug|Release|RelWithDebInfo|MinSizeRel]" FORCE)
endif()

# Set default install prefix.
if (CMAKE_INSTALL_PREFIX STREQUAL "/usr/local")
  set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}")
endif()

# Set flags.
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  /usr/include/OGRE1.7
)

link_directories (
  /usr/lib/OGRE1.7
)

set(HEADER_FILES
  include/engine.h
  include/renderer.h
  include/singleton.h
  include/state.h
  include/timer.h
)

set(SOURCE_FILES
  src/gameengine.cc
  src/ogrerenderengine.cc
  src/timer.cc
)

set(GAME_SOURCE_FILES
  src/game.cc
  src/intro_state.cc
  src/play_state.cc
)

# engine libraray
add_library(engine SHARED
  ${SOURCE_FILES}
)

target_link_libraries (engine
  OgreMain
)

# game executable
add_executable(game
  ${GAME_SOURCE_FILES}
)

target_link_libraries(game
  engine
)

# installation
install(FILES ${HEADER_FILES}
  DESTINATION include/engine
)

install(TARGETS engine
  DESTINATION lib
)
