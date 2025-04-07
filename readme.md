GCC is symlinked to clang, I didn't change it for now use specifc version when running

`gcc-14 --version`

install vcpkg with brew and follow steps to set up
if VSCode terminal is not configured may need to run to locate vcpkg root

`export VCPKG_ROOT="$HOME/vcpkg"`

use vcpkg.json to derfine packages for installation

`vcpkg install --triplet=arm64-osx`

To compile make sure all directories are add to the CMakeList.

<!-- `cd build`
`cmake ..`
`make`

Run program as

`./my_program` -->

# Generate the build files

`cmake -B build -S .`
`cmake --build build`
