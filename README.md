# banjo (100.0000%)

<img src="./progress/progress_total.svg">

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

curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

python3 -m pip install -r requirements.txt
```

### Other versions

Drop in `us.v11`, `jp`, or `pal` as `baserom.<version>.z64` e.g. `baserom.us.v11.z64`

```sh
make VERSION=us.v11
```
