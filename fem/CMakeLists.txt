add_executable(fem
  fem.cpp
)

target_link_libraries(fem
  imaging2
  pthread
  lapack
  GL
  GLU
  glut
  GraphicsMagick
  GraphicsMagick++
)

include_directories(${CMAKE_SOURCE_DIR})
link_directories(${CMAKE_BINARY_DIR})
