# banjo

<img src="./progress/progress_total.svg">

- <img src="./progress/progress_core1.svg">  
- <img src="./progress/progress_core2.svg">  
- <img src="./progress/progress_SM.svg">
- <img src="./progress/progress_MM.svg">
- <img src="./progress/progress_TTC.svg">
- <img src="./progress/progress_CC.svg">
- <img src="./progress/progress_BGS.svg">
- <img src="./progress/progress_FP.svg">
- <img src="./progress/progress_GV.svg">
- <img src="./progress/progress_MMM.svg">
- <img src="./progress/progress_RBB.svg">
- <img src="./progress/progress_CCW.svg">
- <img src="./progress/progress_lair.svg">
- <img src="./progress/progress_fight.svg">
- <img src="./progress/progress_cutscenes.svg">


Grab tools

```sh
git submodule update --init --recursive
```

Drop in `US v1.0` as `baserom.us.v10.z64` (sha1sum: `1fe1632098865f639e22c11b9a81ee8f29c75d7a`)

To extract and build everything

```sh
make extract
make all
```

Build only the rom separately (from all the level and core code sections): 

```sh
make main_extract
make
```

Build a level or core code section separately (from base of repo): 


```sh
make <module_id>
```

Build a level or core code section without re-extracting it: 


```sh
make <module_id>_fast
```

where the following are supported values of `<module_id>`
- `core1` 
- `core2` 
- `MM` 
- `TTC` 
- `CC` 
- `BGS` 
- `FP` 
- `lair` 
- `GV` 
- `CCW` 
- `RBB` 
- `MMM` 
- `SM` 
- `fight` 
- `cutscenes`

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
    wget \
    libssl-dev

python3 -m pip install \
    capstone pyyaml pycparser \
    colorama ansiwrap watchdog python-Levenshtein cxxfilt \
    python-ranges \
    pypng anybadge
```

## Other versions

Drop in `us.v11`, `jp`, or `pal` as `baserom.<version>.z64` e.g. `baserom.us.v11.z64`

```sh
make extract VERSION=us.v11
make VERSION=us.v11
```
