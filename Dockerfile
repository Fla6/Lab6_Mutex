FROM amazonlinux

COPY pingm.py /home/lab6/pingm.py

COPY multipingm.py /home/lab6/multipingm.py

COPY ping.h /home/lab6/ping.h

COPY ping.cpp /home/lab6/ping.cpp

COPY multiping.cpp /home/lab6/multiping.cpp

COPY input2.txt /home/lab6/input2.txt

RUN yum update -y

RUN yum install -y nano

RUN yum install -y gcc-c++

RUN yum install -y python3

RUN yum install -y nmap

ENTRYPOINT bin/bash