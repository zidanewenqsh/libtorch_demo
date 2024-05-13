cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(TorchDemo)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_PREFIX_PATH "/home/wen/libtorch")
find_package(Torch REQUIRED)
message(STATUS "Found Torch: ${TORCH_LIBRARIES}")

# Ensure that the CUDA version matches what you have (CUDA 11.8)
set(CUDA_TOOLKIT_ROOT_DIR "/usr/local/cuda-11.8")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

# 添加运行时库的搜索路径
include_directories(/home/wen/libtorch/include)
link_directories(/home/wen/libtorch/lib)

add_executable(TorchDemo main.cpp)
target_link_libraries(TorchDemo "${TORCH_LIBRARIES}")
set_property(TARGET TorchDemo PROPERTY CXX_STANDARD 14)

if (MSVC)
  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET TorchDemo
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:TorchDemo>)
endif(MSVC)
