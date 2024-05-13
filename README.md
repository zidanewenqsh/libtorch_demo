# libtorch_demo
my libtorch demo

# TorchDemo 项目

这是一个简单的 LibTorch 演示项目，展示了如何在 C++ 中使用 LibTorch 进行基本的张量操作，并支持 CUDA。

## 环境要求

- CMake 3.1 或更高版本
- 如果libtorch 2.3.0 and cuda 11.8, GCC 9 或更高版本（支持 C++17 标准）
- CUDA 11.3
- LibTorch（PyTorch 的 C++ 分发版，需要匹配您的 CUDA 版本）

## 安装步骤

1. 确保您的环境中已安装 GCC、CMake 和 CUDA。
2. 从 [PyTorch 官网](https://pytorch.org) 下载与您的 CUDA 版本相匹配的 LibTorch 版本。[libtorch](https://download.pytorch.org/libtorch/cu113/libtorch-cxx11-abi-shared-with-deps-1.12.1%2Bcu113.zip)
3. 解压 LibTorch 到合适的位置。

## 编译项目

使用以下命令来构建项目：

```bash
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=/absolute/path/to/libtorch ..
make
```

确保替换 `/absolute/path/to/libtorch` 为您解压 LibTorch 的绝对路径。

## 运行程序

在 `build` 目录中，运行编译好的可执行文件：

```bash
./TorchDemo
```

## 功能描述

本项目包括以下几个基本功能：

- 创建随机张量。
- 检查 CUDA 是否可用，并在可用时将张量移至 GPU。
- 显示张量内容。

## 调试项目

如果需要在 VSCode 中调试此项目，请确保您的 `launch.json` 配置正确，以及您已经安装了 C++ 插件并配置了 GDB 或其他调试器。

## 贡献

欢迎通过 Issue 或 Pull Requests 来贡献您的意见或改进。

## 许可证

本项目采用 MIT 许可证。详细信息请查看 `LICENSE` 文件。
