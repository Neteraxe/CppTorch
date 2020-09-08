# CMakeList.txt : CMake project for CppTorch, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project("CppTorch")

set(CMAKE_PREFIX_PATH "E:\\Pytorch\\libtorch\\")

find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_executable(CppTorch "CppTorch.cpp")
target_link_libraries(CppTorch "${TORCH_LIBRARIES}")
set_property(TARGET CppTorch PROPERTY CXX_STANDARD 14)

# The following code block is suggested to be used on Windows.
# According to https://github.com/pytorch/pytorch/issues/25457,
# the DLLs need to be copied to avoid memory errors.
if (MSVC)
  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET CppTorch
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:CppTorch>)
endif (MSVC)
