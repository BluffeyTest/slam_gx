# 所需要的依赖包

## Eigen
---
矩阵包。
### install
```
sudo apt-get install libeigen3-dev
```

### use
in `cpp/hpp`:
```
//such as
#include<Eigen/Core>
#include<Eigen/Geometry>
```

in `CMakeLists.txt`:
```
include_directories("/usr/include/eigen3")
```


## Pangolin
---
3D绘图包。
### install 
```
#安装依赖
sudo apt-get install libglew-dev
sudo apt-get install libpython2.7-dev
sudo apt-get install ffmpeg libavcodec-dev libavutil-dev libavformat-dev libswscale-dev libavdevice-dev
sudo apt-get install libdc1394-22-dev libraw1394-dev
sudo apt-get install libjpeg-dev libpng12-dev libtiff5-dev libopenexr-dev

#下载病编译安装。
git clone https://github.com/stevenlovegrove/Pangolin.git
cd Pangolin
mkdir build
cd build
cmake ..
cmake --build 
```
### use
in`cpp/hpp`:
```
#include <pangolin/pangolin.h>
```

in`CMakeLists.txt`:
```
ind_package(Pangolin 0.4 REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})
```

## Sophus
---
### install 
```
git clone https://github.com/strasdat/Sophus.git

cd Sophus
mkdir build
cd build
cmake ..

make

sudo make install
```

### use
in `cpp/hpp`:
```
//such as
# include "sophus/se3.hpp"
```
in`CMakeLists.txt`:
```
find_package(Sophus REQUIRED)
include_directories(${Sophus_INCLUDE_DIRS})```