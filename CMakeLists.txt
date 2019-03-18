cmake_minimum_required(VERSION 3.3.1)
add_subdirectory(nn)

configure_file(
  "nn.pc.in"
  "nn.pc"
  @ONLY
)

install(
  FILES       "${CMAKE_BINARY_DIR}/nn.pc"
  DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig"
)