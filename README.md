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
- `framework.pri`：Qt 项目文件。
- `tests`：测试代码目录。
    - `unit-tests`：单元测试示例代码目录。
    - `batch-tests`：批量测试示例代码目录。
- `src`：源代码目录。
    - `main.cpp`：应用程序入口。
    - `mainwindow.cpp`：主窗口代码。
    - `mainwindow.h`：主窗口头文件。
    - `mainwindow.ui`：主窗口界面文件。

## 🧪 测试

本项目包含单元测试和批量测试示例，您可以通过以下命令运行测试：

```bash
cd tests/unit-tests
qmake
make
./unit-tests
```

```bash
cd tests/batch-tests
qmake
make
./batch-tests
```

## 📝 许可证

本项目基于 MIT 许可证发布，详情请参阅 [LICENSE](./LICENSE) 文件。