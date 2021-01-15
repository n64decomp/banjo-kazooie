# banjo

Grab n64 splat

```sh
mkdir -p tools && cd tools
git clone https://github.com/ethteck/n64splat.git
```

Drop in `US v1.0` as `baserom.us.v10.z64` (sha1sum: `1fe1632098865f639e22c11b9a81ee8f29c75d7a`)

```sh
make extract
make --jobs
```

Build `core1` separately (from base of repo):

```sh
make decompress
# then, either:
cd core1
make extract
make --jobs
# or:
make -C core1 extract
make -C core1 --jobs
```

Build `core2` separately (from base of repo):

```sh
make decompress
# then, either:
cd core2
make extract
make --jobs
# or:
make -C core2 extract
make -C core2 --jobs
```

## Prerequisites

Ubuntu 18.04 or higher.

```sh
apt-get update && \
  apt-get install -y \
    binutils-mips-linux-gnu \
    build-essential \
    less \
    libglib2.0 \
    python3 \
    python3-pip \
    unzip \
    wget

python3 -m pip install \
    capstone pyyaml pycparser \
    colorama ansiwrap watchdog python-Levenshtein cxxfilt \
    python-ranges \
    pypng
```

## Other versions

Drop in `US v1.1` as `baserom.us.v11.z64` (sha1sum: `ded6ee166e740ad1bc810fd678a84b48e245ab80`)

```sh
make extract VERSION=v11
make VERSION=v11
```
