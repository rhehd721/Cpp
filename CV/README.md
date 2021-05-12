# OpenCV (Open Source Computer Vision Library)

[OpenCV 공식 사이트](http://www.opencv.org).
[OpenCV 문서 사이트](http://www.docs.opencv.org).
[OpenCV 질문 포럼 사이트](http://www.answers.opencv.org/questions).
[OpenCV Github 기본모듈](http://www.github.com/opencv/opencv/).
[OpenCV Github 추가모듈](http://www.github.com/opencv/opencv_contrib/).

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

# OpenCV 모듈

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




