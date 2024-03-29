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
  /home/karsten/apps/ois-1.3/include
  /home/karsten/apps/ogre3d-1.7.3/include
  /home/karsten/apps/cegui-0.7.5/include
)

link_directories (
  /home/karsten/apps/ois-1.3/lib
  /home/karsten/apps/ogre3d-1.7.3/lib
  /home/karsten/apps/cegui-0.7.5/lib
)

set(HEADER_FILES
  include/gameengine.h
  include/inputmanager.h
  include/keybord.h
  include/keys.h
  include/mouse.h
  include/ogrerenderengine.h
  include/oisinputmanager.h
  include/renderengine.h
  include/singleton.h
  include/state.h
  include/timer.h
)

set(SOURCE_FILES
  src/gameengine.cc
  src/inputmanager.cc
  src/keyboard.cc
  src/mouse.cc
  src/ogrerenderengine.cc
  src/oisinputmanager.cc
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
  OIS
  CEGUIBase
  CEGUIOgreRenderer
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
