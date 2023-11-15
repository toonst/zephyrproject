# Zephyr Example Application

This repository contains a Zephyr example application. The main purpose of this
repository is to serve as a reference on how to structure Zephyr based
applications. Some of the features demonstrated in this example are:

- Basic [Zephyr application][app_dev] skeleton
- [Zephyr workspace applications][workspace_app]
- Loosely based on [West T2 topology][west_t2]
- [Custom boards][board_porting]
- Custom [devicetree bindings][bindings]
- Out-of-tree [drivers][drivers]
- Example CI configuration (using Github Actions and bitbucket pipeline)
- Custom [west extension][west_ext]

[app_dev]: https://docs.zephyrproject.org/latest/develop/application/index.html
[workspace_app]: https://docs.zephyrproject.org/latest/develop/application/index.html#zephyr-workspace-app
[west_t2]: https://docs.zephyrproject.org/latest/develop/west/workspaces.html#west-t2
[board_porting]: https://docs.zephyrproject.org/latest/guides/porting/board_porting.html
[bindings]: https://docs.zephyrproject.org/latest/guides/dts/bindings.html
[drivers]: https://docs.zephyrproject.org/latest/reference/drivers/index.html
[zephyr]: https://github.com/zephyrproject-rtos/zephyr
[west_ext]: https://docs.zephyrproject.org/latest/develop/west/extensions.html

We try to structure the code and build the app in a way that stays as
close as possible to the way upstream Zephyr is structured & built. This
has the following advantages:

- easier maintenance of the project
- we can benefit from changes made in the upstream project
- Zephyr documentation can be used to setup the development environment,
  where the setup differs from upstream we document it
- we can make use of the abstraction of the west meta tool, simplifying
  build while at the same time not hiding what is happening from the
  developer
## Getting Started

### Install development environment

Make sure you have a proper Zephyr development environment. You can follow the official
[Zephyr Getting Started Guide](https://docs.zephyrproject.org/latest/getting_started/index.html).

1. Install dependencies
2. Install west within virtual environment
3. Get Zephyr (west update)
4. Install requirements within virtual environment
5. Install Zephyr SDK containing toolchain

> **_NOTE:_**  The **west init** step specified in the zephyr documentation should be skipped,
               the workspace is already initialzed when doing a git clone of this repository

### Python virtual environment

After following the getting started guide, you should have a **Python virtual env** with west tools
and the Zephyr SDK installed. The Python virtual environment makes sure there is no issues with
dependencies, and should be activated from the root of the repo each time before a build with
the following command:

```
source .venv/bin/activate
```

### Initialization

Clone this repository.

```shell
# update Zephyr modules
west update
west zephyr-export
```

### Build

The application can be built by running:

```shell
cd app
west build -b your_board
```

### Flash

Once you have built the application you can flash it by running:

```shell
west flash
```

