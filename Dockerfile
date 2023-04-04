FROM ubuntu:22.04
LABEL authors="laura"

RUN apt-get update \
  && apt-get install -y ssh \
    build-essential \
    gcc \
    g++ \
    gdb \
    cmake \
    rsync \
    tar \
    libglfw3-dev \
    libglfw3 \
    python3 \
    python3-pip \
  && apt-get clean
RUN pip install conan==1.59.0

WORKDIR /app
