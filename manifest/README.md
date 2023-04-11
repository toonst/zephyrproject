# Version management

## Zephyr version management

When building a product using Zephyr, you will utilize the Zephyr source code repository
as a module in your project. There are several strategies to consider for selecting
a Zephyr version and keeping it up to date:

1. Use the Zephyr main branch
	- Always up to date with the latest development
	- The underlying source code might change frequently, leading to potential instability
2. Pin Zephyr to a specific version (e.g., 3.3.0)
	- Source code remains constant until the version is manually updated by the developer
	- No new features or security fixes until a new version is released and updated in the project
3. Use Long Term Support (LTS) branches
	- The most stable option with certification available
	- No new features, but security fixes are backported to ensure a secure and reliable codebase
4. Use Zephyr release branches (e.g., v3.3_branch)
	- Update to a new release branch roughly every 4 months
	- Strikes a balance between new feature integration and stability
	- Backports of security fixes are included, providing a more secure environment

In this project, we follow the latest Zephyr release branch. This approach means that
the Zephyr code may change when running `west update` (and whenever firmware is built
from the CI). However, this is not a concern, as only security fixes and non-breaking
changes are pushed to the release branch, ensuring stability and reliability.

To change the Zephyr version used in the project, change the `revision` in `manifest/west.yml`
and run west update to pull in the latest version.

## Module version management

Three types of modules exist:
1. Upstream Zephyr modules
2. Third party Zephyr modules
2. Proprietary modules

### Upstream Zephyr modules

These are modules defined in the `zephyr/west.yml` upstream manifest file. Each module is in
essence a git repository hosted on the Zephyr project's github. Inside the upstream manifest file,
a revision is defined for each module, based on the commit sha. This ties a certain Zephyr revision
to revisions of the module that are compatible with it.

Zephyr maintainers make sure that upstream modules are updated automatically, so whenever a software
library is available as an upstream module, it is preferred to use it that way.

Upstream modules can be added to the name-allowlist of `manifest/west.yml` and issuing `west update`.

If you want to pin a module to a specific version, that can be done by adding it to
the project list, the same way it is done in the upstream zephyr manifest `zephyr/west.yml`.

### Third party Zephyr modules

These are a lot like upstream modules, but they are not hosted on the Zephyr project github.
To use a third party Zephyr module, you need to add a new remote under the `remotes` section of the
`manifest/west.yml`.

The module can then be added to the `projects` list, specifying the remote and the revision.

### Proprietary modules

For modules that are proprietary, there are two ways to organize the sources:
1. Add module as directory in the application repository
2. Add module in separate private repository

For adding a proprietary module inside the application repository, just add it in the `modules`
directory. To make sure the build system can find it, add it to ZEPHYR_EXTRA_MODULES in
`modules/modules.cmake`:

```
list(APPEND ZEPHYR_EXTRA_MODULES
	${CMAKE_CURRENT_LIST_DIR}/my_module
)
```

For adding a module that is hosted in a separate repository, add the remote to the
`manifest/west.yml` and add the module name and revision to the `projects` list, the same
way it is done for third party modules.

