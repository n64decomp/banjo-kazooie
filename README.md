# banjo (91.1905%)

<img src="./progress/progress_total.svg">

- <img src="./progress/progress_bk_boot.svg">
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

## Building

Grab tools

```sh
git submodule update --init --recursive
```

Drop in `US v1.0` as `baserom.us.v10.z64` (sha1sum: `1fe1632098865f639e22c11b9a81ee8f29c75d7a`)

To extract and build everything

```sh
make
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

### Prerequisites

Ubuntu 18.04 or higher.

```sh
sudo apt-get update && sudo apt-get install -y $(cat packages.txt)

python3 -m pip install -r requirements.txt
```

### Other versions

Drop in `us.v11`, `jp`, or `pal` as `baserom.<version>.z64` e.g. `baserom.us.v11.z64`

```sh
make VERSION=us.v11
```
