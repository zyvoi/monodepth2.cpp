# Monodepth2.cpp
This is a simple inference implementation for a well-known depth estimation network written in C++. The whole project is based on libtorch API.

# steps to run this simple project

1. download related libraries including OpenCV and [libtorch](https://pytorch.org/get-started/locally/).
2. download my converted torchscript [model](https://drive.google.com/file/d/1kZ0H_dWjjv07TvmgbENdhPnkuKQEXt9g/view?usp=sharing) or convert your trained model into torchscript by yourself. If you don't familiar with torchscript currently, please check the offical [docs](https://pytorch.org/tutorials/advanced/cpp_export.html)
3. prepare a sample image and change its path in main.cpp
4. if you don't have available gpus, please annotate CUDA options in CMakeLists.txt
