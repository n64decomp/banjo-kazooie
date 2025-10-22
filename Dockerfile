FROM ubuntu:25.04 AS build
ENV DEBIAN_FRONTEND=noninteractive

WORKDIR /banjo

# (for debug purposes)
RUN echo "System arch: $(uname -a)\nDPKG arch: $(dpkg --print-architecture)"

# Install package dependencies
COPY packages.txt ./
RUN apt-get update && apt-get install -y $(cat packages.txt) && rm packages.txt

# Install Rust/Cargo
# NOTE: We replace /proc/self/exe with /bin/sh in the script to avoid issues with Docker
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sed 's#/proc/self/exe#\/bin\/sh#g' | CARGO_HOME=/opt/cargo sh -s -- -y
ENV PATH=/opt/cargo/bin:$PATH

ENTRYPOINT ["/bin/bash", "-c"]
