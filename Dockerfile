FROM ubuntu:20.04 as build

ENV DEBIAN_FRONTEND=noninteractive

COPY packages.txt /
RUN apt-get update && apt-get install -y $(cat packages.txt)

RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

COPY requirements.txt /
RUN python3 -m pip install -r requirements.txt

RUN mkdir /banjo
WORKDIR /banjo
