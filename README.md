# 📦 Qt 基础框架

本项目是一个基于 Qt 框架的基础框架，旨在帮助开发者快速搭建 Qt 项目。该项目包含了 .pri 项目、单元测试示例和批量测试示例，方便进行项目开发和测试。

## 🛠️ 安装

要使用本项目，您需要先安装 Qt 环境。您可以从 [Qt 官网](https://www.qt.io/download) 下载最新的 Qt 版本并安装。

接下来，您可以通过以下命令将本项目克隆到本地：

```bash
git clone https://github.com/idcpj/qt-basic-framework.git
```

## 📁 项目结构

本项目包含以下文件和文件夹：

```
├── .gitignore
├── README.md
├── framework.pri
├── tests
│   ├── unit-tests
│   │   ├── test-framework.cpp
│   │   └── test-framework.h
│   └── batch-tests
│       ├── batch-test.cpp
│       └── batch-test.h
└── src
    ├── main.cpp
    ├── mainwindow.cpp
    ├── mainwindow.h
    └── mainwindow.ui
```

- `.gitignore`：Git 忽略文件列表。
- `README.md`：项目说明文档。
- `tests`：测试代码目录。
- `src`：源代码目录。
    - `tools`：工具目录。

## 快速入门
### 添加单元测试
在 `test` 目录下,添加文件,注意,单元测试文件必须同时包含 `.h`和`.cpp`文件
并且在 cpp文件下 添加宏
```c++
//QTEST_MAIN(test_add2);
```
测试新文件时,需要去 `tests/tests.pri` 中 开启 `QT_TEST_SINGLE` 宏,并运行

如果需要把文件加入批量测试中 `test/build_batch_test.h` 中加入`testRunner.addTest` class


### 进行批量测试

测试新文件时,需要去 `tests/tests.pri` 中 开启 `QT_TEST` 宏,并运行,即可进行单元测试


## 📝 许可证

本项目基于 MIT 许可证发布，详情请参阅 [LICENSE](./LICENSE) 文件。