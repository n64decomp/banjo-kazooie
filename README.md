# banjo (100.0000%)

<img src="./progress/progress_total.svg">

### Baserom checksums

- `baserom.us.v10.z64`: `1fe1632098865f639e22c11b9a81ee8f29c75d7a`
- `baserom.us.v11.z64`: `ded6ee166e740ad1bc810fd678a84b48e245ab80`
- `baserom.jp.z64`:     `90726d7e7cd5bf6cdfd38f45c9acbf4d45bd9fd8`
- `baserom.pal.z64`:    `bb359a75941df74bf7290212c89fbc6e2c5601fe`

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

### Cloud (GitLab CI)

These are the instructions for building on GitLab CI.
This applies to the main repo - **if you have a fork**, you will need to follow these steps too!

#### 1. Upload the baserom

Upload the file for `US v1.0` as `baserom.us.v10.enc.z64` to a remote server where it can be downloaded from with `wget` or `curl`. The file has to be encrypted with `AES-256-CBC`, as follows:

```sh
openssl enc -aes-256-cbc -salt -in baserom.us.v10.z64 -out baserom.us.v10.enc.z64
```

Then, upload the encrypted file to a server and get a direct download link.

Sharing services like Google Drive, Dropbox, or OneDrive might not work, as they require manual interaction to download the file.

#### 2. Set up environment variables

In your GitLab project, go to `Settings > CI/CD > Variables` and add the following variables (for each version):

- `BASEROM_<VER>_URL`: a direct download URL for the baserom.us.v10.z64 file (see above); this file has to be encrypted with `AES-256-CBC`
- `BASEROM_<VER>_KEY`: the AES key used to encrypt the baserom file above
- `BASEROM_<VER>_SHA1`: the SHA1 checksum of the baserom file; simply use the one mentioned above

Replace `<VER>` with the version you are using:
- `USA10`
- `USA11`
- `JP`
- `PAL`

#### 3. Trigger the pipeline

Push a commit to your repository and you should see a new pipeline starting in the `CI/CD > Pipelines` section! 

## Other versions

Drop in `us.v11`, `jp`, or `pal` as `baserom.<version>.z64` e.g. `baserom.us.v11.z64`

```sh
make VERSION=us.v11
```
