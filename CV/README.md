# OpenCV (Open Source Computer Vision Library)

- [OpenCV 공식 사이트](http://www.opencv.org)
- [OpenCV 문서 사이트](http://www.docs.opencv.org)
- [OpenCV 질문 포럼 사이트](http://www.answers.opencv.org/questions)
- [OpenCV Github 기본모듈](http://www.github.com/opencv/opencv/)
- [OpenCV Github 추가모듈](http://www.github.com/opencv/opencv_contrib/)

# 개요

## 디저털 카메라에서 사진을 촬영하는 과정
피사체 -> 렌즈() -> 이미지 센서 -> ADC -> ISP -> 사진파일

- 이미지 센서
    - 빛을 전기적 신호로 변환하는 포토 다이오드(photodiode)가 2차원 평면상 배열되어 있는 장치
- ADC(Ananlog-to-Digital Convertor)
    - 아날로그 신호를 디지털 신호로 변환
- ISP(Image Signal Processor)
    - 화이트밸런스 조정, 색 보정, 잡음 제거

## Grayscale VS Truecolor
- Grayscale Image
    - 영상의 밝기 정보를 256단계로 구분하여 표현 (0(어두움) ~ 255(밝음))
    - unsigned char 자료형을 사용하여 Grayscale 값 저장
- Truecolor Image
    - Grayscale + R + G + B

## BMP, JPG, GIF, PNG
- BMP : 픽셀 데이터를 압축하지 않은 상태로 저장(파일구조 간단하지만 용량이 크다)
- JPG : 주로 트루컬러 영상 저장을 위해 사용(손실압축 사용, 용량 감소)
- GIF : 256 이하의 색상을 가진 영상만 저장 가능한 포맷(무손실 압축)
- PNG : 트루컬러, 그레이스케일 모두 지원(무손실 압축, 큰 용량)

## 주요 모듈
- calib3d : 카메라 캘리브레이션과 3차원 재구성
- core : 행렬, 벡터 등 OpenCV 핵심 클래스와 연산 함수
- dnn : 심층 신경망 기능
- feature2d : 2차원 특징 추출과 특징 벡터 기술, 매칭 방법
- flann : 다차원 공간에서 빠른 최근방 이웃 검색
- highgui : 영상의 화면 출력, 마우스 이벤트 처리 등 사용자 인터페이스
- imgcodecs : 영상 파일 입출력
- imgproc : 필터링, 기하학적 변환, 색 공간 변환 등 영상 처리 기능
- ml : 통계적 분류, 회기 등 머신 러닝 알고리즘
- objdetect : 얼굴, 보행자 검풀 등 객체 검출
- photo : HDR, 잡음 제거 등 사진 처리 기능
- stitching : 영상 이어 붙이기
- video : 옵티컬 플로우, 배경 차분 등 동영상 처리 기술
- videoio : 동영상 파일 입출력
- world : 여러 OpenCV 모듈을 포함하는 하나의 통합 모듈

![OpenCV 모듈](./image/module.jpeg)

# OpenCV 설치
Window
- [OpenCV 4.0.0 Download](http://www.github.com/opencv/opencv/releases/tag/4.0.0)

Mac
- brew install opencv
    - /usr/local/Cellar/opencv/ 경로에 설치
- OpenCV 환경설정
- brew install pkg-config
- 환경변수 설정
    - $ export PKG_CONFIG_PATH=/usr/local/Cellar/opencv/4.5.1_3/lib/pkgconfig

Linux (560p 참조)
- 업데이트
    - sudo apt update
    - sudo apt upgrade
- 소스 코드 빌드에 필요한 패키지
    - sudo apt install build-essential cmake pkg--config
- 다양한 정지 영상 파일 불러오거나 저장하기 위한 패키지
    - sudo apt install libjpeg-dev libtiff5-dev libpng-dev
- 동영상 파일을 다루거나 캄퓨터에 연결된 카메라를 활용하기 위해 필요한 패키지 설치
    - sudo apt install libavcode-dev libavformat-dev libswscale-dev
    - sudo apt install libdc1394-22-dev libxvidcore-dev libx264-dev
    - sudo apt install libxine2-dev libv4l-dev v4l-utils
    - sudo apt install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev
- 그래픽 툴킷 GTK 설치
    - sudo apt install libgtk-3-dev
- 최적화 관련 패키지 및 python3 개발 환경을 위한 패키지
    - sudo apt install libatlas-base-dev libeigen3-dev gfortran
    - sudo apt install python3-dev python3-numpy libtbb2 libtbb-dev
- download opensource module
    - wget -O opencv-4.0.0.zip https://github.com/opencv/opencv/archive/4.0.0.zip
    - wget -O opencv_contrib-4.0.0.zip https://github.com/opencv/opencv_contrib/archive/4.0.0.zip
    - wget == 웹 서버에서 특정 파일을 다운받는 명령어
- unzip
    - unzip opencv-4.0.0.zip
    - unzip opencv_contrib-4.0.0.zip
- cmake
```cmd
cmake \ 
-D CMAKE_BUILD_TYPE=Release \
-D CMAKE_INSTALL_PREFIX=/usr/local \
-D BUILD_WITH_DEBUG_INFO=OFF \
.
.
.
```