FROM ubuntu:latest
WORKDIR /code
RUN apt install cmake g++ make libsfml-dev
COPY . .
RUN cd build
CMD ["cmake ..;", "make"]
