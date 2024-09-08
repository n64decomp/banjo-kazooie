FROM ubuntu:20.04 AS build
ENV DEBIAN_FRONTEND=noninteractive

# (for debug purposes)
RUN echo "System arch: $(uname -a)\nDPKG arch: $(dpkg --print-architecture)"

# Install package dependencies
COPY packages.txt ./
RUN apt-get update && apt-get install -y $(cat packages.txt) && rm packages.txt

# Install Rust/Cargo
# NOTE: We replace /proc/self/exe with /bin/sh in the script to avoid issues with Docker
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sed 's#/proc/self/exe#\/bin\/sh#g' | CARGO_HOME=/opt/cargo sh -s -- -y
ENV PATH=/opt/cargo/bin:$PATH

# Install Python dependencies
COPY requirements.txt ./
COPY tools/n64splat/requirements.txt ./tools/n64splat/requirements.txt
RUN python3 -m pip install -r requirements.txt

WORKDIR /banjo
ENTRYPOINT ["/bin/bash", "-c"]
