FROM ubuntu:22.04
LABEL authors="laura"

RUN apt-get update \
  && apt-get install -y ssh \
    build-essential \
    gcc \
    g++ \
    gdb \
    clang \
    cmake \
    rsync \
    tar \
    libglfw3-dev \
    libglfw3 \
  && apt-get clean

WORKDIR /app
COPY . .

RUN mkdir build
WORKDIR /app/build
CMD ["cmake", ".."]
ENTRYPOINT ["make", "test_so_long"]