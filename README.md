# banjo (100.0000%)

<img src="./progress/progress_total.svg">

### Baserom checksums

- `baserom.us.v10.z64`: `1fe1632098865f639e22c11b9a81ee8f29c75d7a`
- `baserom.us.v11.z64`: TODO
- `baserom.jp.z64`: TODO
- `baserom.pal.z64`: TODO

## Building

The following instructions should work on the following platforms:
- Ubuntu 18.04 or higher (x86_64)
- Docker only
    - Linux (x86_64, ARM)
    - macOS (x86_64, ARM)

### Local (Linux)

Works with Ubuntu 18.04 or higher.

#### 1. Install dependencies

```sh
sudo apt-get update && sudo apt-get install -y $(cat packages.txt)
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
python3 -m pip install -r requirements.txt
```

#### 2. Grab tools

```sh
git submodule update --init --recursive
cd tools/n64splat
python3 -m pip install -r requirements.txt
```

#### 3. Add baserom

Add the file for `US v1.0` as `baserom.us.v10.z64` in the project folder.

(optional): Check the baserom checksum

```sh
sha1sum baserom.us.v10.z64
```

The output should match the checksum specified above.

#### 4. Build

To extract and build everything simply run:

```sh
make
```

If you want to build a specific module, instead do:

```sh
make <module_id>
```

...where the following are supported values of `<module_id>`
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

### Local (Docker - Linux/macOS)

#### 1. Get the Docker image

(if available) you can pull it from GitLab (but you need to be logged in):

```sh
docker login registry.gitlab.com
docker pull registry.gitlab.com/banjo.decomp/banjo-kazooie:latest
```

(otherwise) you can build it yourself:

```sh
docker build -t banjo-kazooie .
```

**NOTE for ARM users** (Windows ARM, Raspberry Pi and similar, or Apple Silicon): Use this command instead:

```sh
docker build --platform linux/amd64 -t banjo-kazooie .
```

#### 2. Add baserom

Follow the same instructions as Step 3 above in "Local (Linux)".

#### 3. Run the Docker container

```sh
docker run -it --rm -v $(pwd):/banjo banjo-kazooie 
```

**NOTE for ARM users**: Use this command instead:

```sh
docker run --platform linux/amd64 -it --rm -v $(pwd):/banjo banjo-kazooie 
```

#### 4. Build

Follow the same instructions as Step 4 above in "Local (Linux)".

To exit Docker, simply type `exit`.

## Other versions

Drop in `us.v11`, `jp`, or `pal` as `baserom.<version>.z64` e.g. `baserom.us.v11.z64`

```sh
make VERSION=us.v11
```
